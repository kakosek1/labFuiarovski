#ifndef DATA_H
#define DATA_H
typedef struct {
	char full_name[50];
	char position[50];
	float salary;
	char dpt[50];
	int date;
} Employee;
extern Employee* employees;
extern int kolvo;
extern int capacity;
void remove_newline(char* str);
void expand_array(int additional_elements);
void clear_all_memory(void);
void add_employee(void);
void all_employees(void);
void edit_employee(void);
void search_employee(void);
void remove_last_employee(void);
void manual_expand(void);
void sort_employees(void);
void insert_at_position(void);
void delete_by_index(void);
void save_to_file(const char* filename);
void load_from_file(const char* filename);
#endif
