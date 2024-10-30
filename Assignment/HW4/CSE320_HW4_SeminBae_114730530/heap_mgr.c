/* Name : Semin Bae (114730530)
   E-mail : semin.bae@stonybrook.edu */

#include "common.h"
#include "heap_mgr.h"

//forward declarations
static void     init_heap(heap_mgr_t *self);
static block_t *extend_heap(heap_mgr_t *self, size_t size);
static block_t *coalesce(heap_mgr_t *self, block_t *curr);
static block_t *find_free_block(heap_mgr_t *self, size_t size);
static size_t   mem_aligned_size(heap_mgr_t *self, size_t size);
static void    *mem_alloc(heap_mgr_t *self, size_t size);
static void     mem_free(heap_mgr_t *self, void *ptr);

static void init_heap(heap_mgr_t *self) {
    block_mgr_t *bmgr = self->bmgr;
    memory_t *heap = self->heap;
    block_t *curr, *next;

    //initialize the first block
    curr = heap->sbrk(heap, 4*sizeof(block_hdr_t));
    curr->prev_footer = 0; //padding
    bmgr->set_header(curr, 2*sizeof(block_hdr_t), 1); //prolog
    
    //initialize the last block
    next = bmgr->next(curr);
    next->header = bmgr->hdr_make_epilog(); //epilog

    //set the block list head
    self->blist_head = curr;
}

static block_t *extend_heap(heap_mgr_t *self, size_t size) {
    block_mgr_t *bmgr = self->bmgr;
    memory_t *heap = self->heap;

    //adjust size
    if(size < self->brk_min_incr)
        size = self->brk_min_incr;
    size = self->mem_aligned_size(self, size);

    //find and update the last block
    //TODO: increase brk and get the oldbrk

    // Expand the heap by 'size' and save the previous end (oldbrk) //
    char *last_sbrk = heap -> sbrk(heap, size);


    //TODO: from the oldbrk, find the last block (its containing block)

    // Get the block containing oldbrk, using it as the start of the block’s data //
    block_t *last_block = containerof(last_sbrk, block_t, payload);


    //TODO: set the header of the last block

    // Set the header of the last block with size and mark it as free (0) //
    bmgr -> set_header(last_block, size, 0);


    //the new last block
    //TODO: get the next block of the last block

    // Get the next block that follows last_block //
    block_t *new_block = bmgr -> next(last_block);


    //TODO: copy epilog to the header of the block

    // Mark the end of the heap with an epilog in the new block’s header //
    new_block -> header = bmgr -> hdr_make_epilog();


    //TODO: coalese the last block and return the result
    
    // Merge free blocks if possible, and return the updated block //
    return self -> coalesce(self, last_block);
}

static block_t *coalesce(heap_mgr_t *self, block_t *curr) {
    block_mgr_t *bmgr = self->bmgr;
    block_t *prev = bmgr->prev(curr);
    block_t *next = bmgr->next(curr);

    //TODO: handle the four cases

    // Those are the way of four possible cases when we are going to coalesce, which is shown class slide. //
    if(bmgr->inuse(prev) &&
       bmgr->inuse(next)) {
        // Case 1: Both previous and next blocks are in use //
        return curr;
    }
    else if( bmgr->inuse(prev) &&
            !bmgr->inuse(next)) {
                bmgr -> set_header(curr, bmgr -> size(curr) + bmgr -> size(next), 0);
                // Case 2: Previous block is in use, next block is free //
                return curr;
    }
    else if(!bmgr->inuse(prev) &&
             bmgr->inuse(next)) {
                // Case 3: Previous block is free, next block is in use //
                bmgr -> set_header(prev, bmgr -> size(curr) + bmgr -> size(prev), 0);
                return prev;
    }
    else {
        // Case 4: Both previous and next blocks are free //
        bmgr -> set_header(prev, bmgr -> size(curr) + bmgr -> size(next) + bmgr -> size(prev), 0);
        bmgr -> set_header(next, bmgr -> size(curr) + bmgr -> size(next) + bmgr -> size(prev), 0);
        return prev;
    }
}

static block_t *find_free_block(heap_mgr_t *self, size_t size) {
    block_mgr_t *bmgr = self->bmgr;
    block_hdr_t epilog = bmgr->hdr_make_epilog();
    block_t *pos;

    //TODO: find and return a free block whose size is at least size

    /* Search for a free block with at least 'size' memory and start from the head of the block list
         and check each block stop when reaching the epilog (end marker) */
    for(pos = self->blist_head; pos->header != epilog; pos = bmgr->next(pos)){
        if(!bmgr->inuse(pos) && bmgr->size(pos) >= size) return pos;
    }
    return NULL; // No suitable block found
}

static size_t mem_aligned_size(heap_mgr_t *self, size_t size) {
    size_t align_size = self->mem_align;
    return ((size + align_size - 1) / align_size) * align_size;
}

static void *mem_alloc(heap_mgr_t *self, size_t size) {
    block_mgr_t *bmgr = self->bmgr;
    block_t *curr;
    size_t next_size;

    size = self->mem_aligned_size(self, size + 2*sizeof(block_hdr_t));

    //TODO: find a free block larger than size or extend the heap
    
    // Find a free block of sufficient size or expand the heap if needed //
    curr = find_free_block(self, size);
    if (curr == NULL) curr = extend_heap(self, size);
    
    //TODO: compute next_size. next_size is the size of the remaining
    
    // Calculate the size of the remaining space after allocation (next_size)
    next_size = bmgr -> size(curr) - size;

    //TODO: set the header of the free block
    
    // Set the header of the allocated block and mark it as in-use (1)
    bmgr -> set_header(curr, size, 1);

    if(next_size >= 2*sizeof(block_hdr_t)) {
        //split
        //TODO: set the header of the remaining block

        // If remaining space is enough for a new block, set its header //
        bmgr -> set_header(bmgr -> next(curr), next_size, 0);
    }
    else {
        //no split
        ON_FALSE_EXIT(next_size == 0, "unexpected next size");
    }

    //TODO: return the address of the curr's payload
    
    // Return the address of the payload section of the allocated block //
    return &(curr -> payload);
}

static void mem_free(heap_mgr_t *self, void *ptr) {
    block_mgr_t *bmgr = self->bmgr;
    block_t *curr;

    //TODO: find the block_t address of ptr

    // Find the block_t address from the given payload pointer (ptr)
    curr = containerof(ptr, block_t, payload);

    //TODO: update the inuse field of curr
    
    // Mark the block as free by updating the header's inuse field to 0 //
    bmgr->set_header(curr, bmgr->size(curr), 0);

    //TODO: coalese

    // Coalesce (merge) with neighboring free blocks if possible //
    self->coalesce(self, curr);
}

heap_mgr_t *make_heap_mgr_default() {
    return make_heap_mgr(1<<20/*1MB*/, 1<<12/*4KB*/);
}

heap_mgr_t *make_heap_mgr(size_t mem_size, size_t brk_min_incr) {
    heap_mgr_t *hmgr = malloc(sizeof(heap_mgr_t));

    // constants
    hmgr->mem_align    = 2*sizeof(block_hdr_t); //16
    hmgr->mem_size     = mem_size;
    hmgr->brk_min_incr = brk_min_incr; 
    hmgr->blist_head   = NULL;

    // function pointers
    hmgr->init_heap        = init_heap;
    hmgr->extend_heap      = extend_heap;
    hmgr->coalesce         = coalesce;
    hmgr->find_free_block  = find_free_block;
    hmgr->mem_aligned_size = mem_aligned_size;
    hmgr->malloc           = mem_alloc;
    hmgr->free             = mem_free;

    // related structures
    hmgr->heap = make_memory(hmgr->mem_size);
    hmgr->bmgr = make_block_mgr();
    hmgr->init_heap(hmgr);

    return hmgr;
}

