#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

void remove_newline(char* str) {
	int len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}

typedef struct {
	char full_name[50];
	char position[50];
	float salary;
	char dpt[50];
	int date;
} Employee;
Employee* employees = NULL;
int kolvo = 0;
int capacity = 0;
void expand_array(int additional_elements) {
	int new_capacity = capacity + additional_elements;
	Employee* new_employees = (Employee*)malloc(new_capacity * sizeof(Employee));

	if (new_employees == NULL) {
		printf("Ошибка выделения памяти!\n");
		return;
	}
	for (int i = 0; i < kolvo; i++) {
		new_employees[i] = employees[i];
	}
	if (employees != NULL) {
		free(employees);
	}
	employees = new_employees;
	capacity = new_capacity;

	printf("Массив расширен! Новая вместимость: %d\n", capacity);
}
void add_employee() {
	if (kolvo >= capacity) {
		printf("Массив заполнен, расширяю на 5 мест...\n");
		expand_array(5);
	}

	printf("Режим добавления сотрудника\n");
	getchar();

	printf("Введите ФИО сотрудника: ");
	fgets(employees[kolvo].full_name, 50, stdin);
	remove_newline(employees[kolvo].full_name);

	printf("Введите позицию сотрудника: ");
	fgets(employees[kolvo].position, 50, stdin);
	remove_newline(employees[kolvo].position);;

	printf("Введите зарплату сотрудника: ");
	scanf("%f", &employees[kolvo].salary);
	getchar();

	printf("Введите отдел сотрудника: ");
	fgets(employees[kolvo].dpt, 50, stdin);
	remove_newline(employees[kolvo].dpt);

	printf("Введите дату наёма сотрудника(удобным вам форматом): ");
	scanf("%d", &employees[kolvo].date);

	kolvo++;

	printf("\nСотрудник добавлен\n");
}
void all_employees() {
	if (kolvo == 0) {
		printf("Некого показывать!\n");
		return;
	}
	for (int i = 0; i < kolvo; i++) {
		printf("\nСотрудник %d\n", i);
		printf("ФИО: %s\n", employees[i].full_name);
		printf("Должность: %s\n", employees[i].position);
		printf("Зарплата: %f\n", employees[i].salary);
		printf("Отдел: %s\n", employees[i].dpt);
		printf("Дата найма: %d\n", employees[i].date);
	}
	printf("\n");
}
void edit_employee() {
	if (kolvo == 0) {
		printf("Некого редактировать!\n");
		return;
	}
	int index = 0;
	printf("Введите индекс сотрудника (0 - 10): ");
	scanf("%d", &index);

	if (index < 0 || index >= kolvo) {
		printf("Неверный индекс!\n");
		return;
	}
	printf("\nТекущие данные сотрудника [%d]:\n", index);
	printf("ФИО: %s\n", employees[index].full_name);
	printf("Должность: %s\n", employees[index].position);
	printf("Зарплата: %f\n", employees[index].salary);
	printf("Отдел: %s\n", employees[index].dpt);
	printf("Дата: %d\n", employees[index].date);

	int choice;
	printf("Что вы хотите изменить?\n");
	printf("1. ФИО\n");
	printf("2. Должность\n");
	printf("3. Зарплату\n");
	printf("4. Отдел\n");
	printf("5. Дату приема\n");
	printf("0. Отмена\n");
	printf("Ваш выбор: ");
	scanf("%d", &choice);
	getchar();

	switch (choice) {
	case 1:
		printf("Новое ФИО: ");
		fgets(employees[index].full_name, 50, stdin);
		remove_newline(employees[index].full_name);
		printf("ФИО обновлено!\n");
		break;

	case 2:
		printf("Новая должность: ");
		fgets(employees[index].position, 50, stdin);
		remove_newline(employees[index].position);
		printf("Должность обновлена!\n");
		break;

	case 3:
		printf("Новая зарплата: ");
		scanf("%f", &employees[index].salary);
		printf("Зарплата обновлена!\n");
		break;

	case 4:
		printf("Новый отдел: ");
		fgets(employees[index].dpt, 50, stdin);
		remove_newline(employees[index].dpt);
		printf("Отдел обновлен!\n");
		break;

	case 5:
		printf("Новая дата найма: ");
		scanf("%d", &employees[index].date);
		printf("Дата обновлена!\n");
	case 0:
		printf("Остановка\n");
		break;

	default:
		printf("Неверный выбор\n");
	}
}
void search_employee() {
	if (kolvo == 0) {
		printf("\nНикого нет!\n");
		return;
	}

	int choice;
	printf("\nПоиск сотрудника\n");
	printf("Искать по:\n");
	printf("1. ФИО\n");
	printf("2. Отделу\n");
	printf("3. Должности\n");
	printf("Ваш выбор: ");
	scanf("%d", &choice);
	getchar();

	char search_term[100];
	int found = 0;

	switch (choice) {
	case 1:
		printf("Введите ФИО (или часть): ");
		fgets(search_term, 100, stdin);
		remove_newline(search_term);

		printf("\nРезультаты поиска:\n");
		for (int i = 0; i < kolvo; i++) {
			if (strstr(employees[i].full_name, search_term) != NULL) {
				printf("\n[%d]\n", i);
				printf("ФИО: %s\n", employees[i].full_name);
				printf("Должность: %s\n", employees[i].position);
				printf("Зарплата: %f\n", employees[i].salary);
				printf("Отдел: %s\n", employees[i].dpt);
				found++;
			}
		}
		break;

	case 2:
		printf("Введите название отдела: ");
		fgets(search_term, 100, stdin);
		remove_newline(search_term);

		printf("\nРезультаты поиска:\n");
		for (int i = 0; i < kolvo; i++) {
			if (strstr(employees[i].dpt, search_term) != NULL) {
				printf("\n[%d]\n", i);
				printf("ФИО: %s\n", employees[i].full_name);
				printf("Должность: %s\n", employees[i].position);
				printf("Зарплата: %f\n", employees[i].salary);
				found++;
			}
		}
		break;

	case 3:
		printf("Введите должность: ");
		fgets(search_term, 100, stdin);
		remove_newline(search_term);

		printf("\nРезультаты поиска:\n");
		for (int i = 0; i < kolvo; i++) {
			if (strstr(employees[i].position, search_term) != NULL) {
				printf("\n[%d]\n", i);
				printf("ФИО: %s\n", employees[i].full_name);
				printf("Зарплата: %f\n", employees[i].salary);
				printf("Отдел: %s\n", employees[i].dpt);
				found++;
			}
		}
		break;

	default:
		printf("Неверный выбор!\n");
		return;
	}

	if (found == 0) {
		printf("\nНичего не найдено.\n");
	}
	else {
		printf("\nНайдено: %d сотрудников\n", found);
	}
}
void remove_last_employee() {
	if (kolvo == 0) {
		printf("\nМассив пуст, удалять нечего!\n");
		return;
	}

	kolvo--;
	int new_capacity = kolvo;

	if (new_capacity == 0) {
		free(employees);
		employees = NULL;
		capacity = 0;
		printf("Последний сотрудник удален! Массив очищен.\n");
		return;
	}
	Employee* new_employees = (Employee*)malloc(new_capacity * sizeof(Employee));

	if (new_employees == NULL) {
		printf("Ошибка выделения памяти!\n");
		kolvo++;
		return;
	}
	for (int i = 0; i < kolvo; i++) {
		new_employees[i] = employees[i];
	}
	free(employees);
	employees = new_employees;
	capacity = new_capacity;
	printf("Последний сотрудник удален! (осталось: %d/%d)\n", kolvo, capacity);
}

void clear_all_memory() {
	if (employees != NULL) {
		free(employees);
		employees = NULL;
	}
	kolvo = 0;
	capacity = 0;
	printf("Вся память освобождена!\n");
}

void manual_expand() {
	int add_count = 0;
	printf("\nНа сколько элементов расширить массив? ");
	scanf("%d", &add_count);

	if (add_count <= 0) {
		printf("Неверное количество!\n");
		return;
	}

	expand_array(add_count);
}
int main() {
	setlocale(LC_ALL, ".UTF8");
	employees = (Employee*)malloc(3 * sizeof(Employee));
	if (employees == NULL) {
		printf("Ошибка выделения начальной памяти!\n");
		return 1;
	}
	capacity = 3;
	printf("Начальная вместимость: %d элементов\n\n", capacity);

	int choice;

	while (1) {
		printf("\n--- Текущее: %d/%d ---\n", kolvo, capacity);
		printf("1 - Добавление сотрудника\n");
		printf("2 - Показ всех сотрудников\n");
		printf("3 - Редактирование информации о сотруднике\n");
		printf("4 - Поиск сотрудника по критерию\n");
		printf("5 - Удалить последнего сотрудника\n");
		printf("6 - Расширить массив вручную\n");
		printf("7 - Очистить всю память\n");
		printf("0 - Выход из программы\n");
		printf("Ваш выбор: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			add_employee();
			break;
		case 2:
			all_employees();
			break;
		case 3:
			edit_employee();
			break;
		case 4:
			search_employee();
			break;
		case 5:
			remove_last_employee();
			break;
		case 6:
			manual_expand();
			break;
		case 7:
			clear_all_memory();
			break;

		case 0:
			printf("\nОчистка памяти перед выходом...\n");
			clear_all_memory();
			printf("\nВыход.\n");
			return 0;

		default:
			printf("\nНеверный выбор!\n");
		}
	}

	return 0;
}