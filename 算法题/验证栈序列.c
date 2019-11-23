typedef struct stack
{
    int num[1000],len;
}stack;
void Init(stack* s)
{
    s->len=-1;
}
void push(stack *s,int n)
{
    s->len++;
    s->num[s->len]=n;
}
int pop(stack *s)
{
    s->len--;
    return s->num[s->len+1];
}
int top(stack *s)
{
    return s->num[s->len];
}
int validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    stack s;
    Init(&s);
    int i=0,j=0;
    for(i=0;i<pushedSize;i++)
    {
        push(&s,pushed[i]);
        while(s.len!=-1 && j<poppedSize && top(&s)==popped[j])
        {
            pop(&s);
            j++;
        }
    }
    return j==poppedSize;
}
