typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Deque;


Deque* createDeque(int capacity) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(sizeof(int)*capacity);
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
    return dq;
}


int isEmpty(Deque* dq) {
    return dq->size == 0;
}

void pushBack(Deque* dq, int val) {
    dq->rear = (dq->rear + 1) % dq->size;
    dq->data[dq->rear] = val;
    dq->size++;
}


void popFront(Deque* dq) {
    dq->front = (dq->front + 1) % dq->size;
    dq->size--;
}


void popBack(Deque* dq) {
    dq->rear = (dq->rear - 1 + dq->size) % dq->size;
    dq->size--;
}


int front(Deque* dq) {
    return dq->data[dq->front];
}


int back(Deque* dq) {
    return dq->data[dq->rear];
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int* result = (int*)malloc(sizeof(int)*(numsSize - k + 1));
    int resIndex = 0;
    
    
    int *dq = (int*)malloc(sizeof(int)*numsSize);
    int front = 0, rear = -1;
    
    for (int i = 0; i < numsSize; i++) {
        
        while (rear >= front && nums[dq[rear]] <= nums[i]) {
            rear--;
        }
     
        dq[++rear] = i;
        
    
        if (dq[front] <= i - k) {
            front++;
        }
        
      
        if (i >= k - 1) {
            result[resIndex++] = nums[dq[front]];
        }
    }
    
    free(dq);
    *returnSize = resIndex;
    return result;
}
