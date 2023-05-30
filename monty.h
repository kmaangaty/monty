#ifndef monty_h
#define monty_h

/**
 * struct stack_s - type struct
 * @n: parameter of type int
 * @prev: parameter of type struct
 * @next: parameter of type parameter of type int
 *
 * Description: val
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - type struct
 *
 * @opcode: parameter of type char
 * @f: parameter of type void
 *
 * Description: val
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct queue_s - type struct
 *
 * @line: parameter of type char
 * @line_number: parameter of type int
 * @prev: parameter of type struct
 * @next: parameter of type struct
 *
 * Description: val
 */
typedef struct queue_s
{
	char *line;
	int line_number;
	struct queue_s *prev;
	struct queue_s *next;
} queue_t;

void enqueue(char *, int);
void print_queue(void);
queue_t *deque(void);
stack_t *deque_value(void);
void enqueue_values(int);
void interpret(void);
void unknown_instruction(queue_t *node, char *token);

void push_error(queue_t *);
void push(stack_t **, unsigned int);
void push_error(queue_t *);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **stack, unsigned int line_number);

void free_queue(void);
void free_values(void);

#endif /* monty_h */
