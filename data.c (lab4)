#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"

Employee* employees = NULL;
int kolvo = 0;
int capacity = 0;


void remove_newline(char* str) {
	int len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}


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


void add_employee(void) {
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
	remove_newline(employees[kolvo].position);

	printf("Введите зарплату сотрудника: ");
	scanf("%f", &employees[kolvo].salary);
	getchar();

	printf("Введите отдел сотрудника: ");
	fgets(employees[kolvo].dpt, 50, stdin);
	remove_newline(employees[kolvo].dpt);

	printf("Введите дату наёма сотрудника: ");
	scanf("%d", &employees[kolvo].date);

	kolvo++;

	printf("\nСотрудник добавлен\n");
}


void all_employees(void) {
	if (kolvo == 0) {
		printf("Некого показывать!\n");
		return;
	}
	for (int i = 0; i < kolvo; i++) {
		printf("\nСотрудник %d\n", i);
		printf("ФИО: %s\n", employees[i].full_name);
		printf("Должность: %s\n", employees[i].position);
		printf("Зарплата: %.2f\n", employees[i].salary);
		printf("Отдел: %s\n", employees[i].dpt);
		printf("Дата найма: %d\n", employees[i].date);
	}
	printf("\n");
}


void edit_employee(void) {
	if (kolvo == 0) {
		printf("Некого редактировать!\n");
		return;
	}
	int index = 0;
	printf("Введите индекс сотрудника (0 - %d): ", kolvo - 1);
	scanf("%d", &index);

	if (index < 0 || index >= kolvo) {
		printf("Неверный индекс!\n");
		return;
	}
	printf("\nТекущие данные сотрудника [%d]:\n", index);
	printf("ФИО: %s\n", employees[index].full_name);
	printf("Должность: %s\n", employees[index].position);
	printf("Зарплата: %.2f\n", employees[index].salary);
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
		break;
	case 0:
		printf("Остановка\n");
		break;
	default:
		printf("Неверный выбор\n");
	}
}


void search_employee(void) {
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
				printf("Зарплата: %.2f\n", employees[i].salary);
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
				printf("Зарплата: %.2f\n", employees[i].salary);
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
				printf("Зарплата: %.2f\n", employees[i].salary);
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


void remove_last_employee(void) {
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


void clear_all_memory(void) {
	if (employees != NULL) {
		free(employees);
		employees = NULL;
	}
	kolvo = 0;
	capacity = 0;
	printf("Вся память освобождена!\n");
}


void manual_expand(void) {
	int add_count = 0;
	printf("\nНа сколько элементов расширить массив? ");
	scanf("%d", &add_count);

	if (add_count <= 0) {
		printf("Неверное количество!\n");
		return;
	}

	expand_array(add_count);
}


void sort_employees(void) {
	if (kolvo == 0) {
		printf("\nМассив пуст, сортировать нечего!\n");
		return;
	}

	int choice = 0;
	printf("\nСортировка сотрудников\n");
	printf("Сортировать по:\n");
	printf("1. ФИО (по алфавиту)\n");
	printf("2. Зарплате (по возрастанию)\n");
	printf("3. Дате найма (по возрастанию)\n");
	printf("Ваш выбор: ");
	scanf("%d", &choice);

	for (int i = 0; i < kolvo - 1; i++) {
		for (int j = 0; j < kolvo - i - 1; j++) {
			int swap_needed = 0;

			switch (choice) {
			case 1:
				if (strcmp(employees[j].full_name, employees[j + 1].full_name) > 0) {
					swap_needed = 1;
				}
				break;
			case 2:
				if (employees[j].salary > employees[j + 1].salary) {
					swap_needed = 1;
				}
				break;
			case 3:
				if (employees[j].date > employees[j + 1].date) {
					swap_needed = 1;
				}
				break;
			default:
				printf("Неверный выбор!\n");
				return;
			}

			if (swap_needed) {
				Employee temp = employees[j];
				employees[j] = employees[j + 1];
				employees[j + 1] = temp;
			}
		}
	}

	printf("Массив отсортирован!\n");
}


void insert_at_position(void) {
	if (kolvo >= capacity) {
		printf("Массив заполнен, расширяю на 5 мест...\n");
		expand_array(5);
	}

	int position = 0;
	printf("\nВставка сотрудника на указанную позицию\n");
	printf("Введите позицию (0-%d): ", kolvo);
	scanf("%d", &position);

	if (position < 0 || position > kolvo) {
		printf("Неверная позиция!\n");
		return;
	}

	for (int i = kolvo; i > position; i--) {
		employees[i] = employees[i - 1];
	}

	getchar();

	printf("\nВвод данных для позиции [%d]:\n", position);
	printf("Введите ФИО сотрудника: ");
	fgets(employees[position].full_name, 50, stdin);
	remove_newline(employees[position].full_name);

	printf("Введите позицию сотрудника: ");
	fgets(employees[position].position, 50, stdin);
	remove_newline(employees[position].position);

	printf("Введите зарплату сотрудника: ");
	scanf("%f", &employees[position].salary);
	getchar();

	printf("Введите отдел сотрудника: ");
	fgets(employees[position].dpt, 50, stdin);
	remove_newline(employees[position].dpt);

	printf("Введите дату наёма сотрудника: ");
	scanf("%d", &employees[position].date);

	kolvo++;

	printf("\nСотрудник вставлен на позицию %d! (всего: %d)\n", position, kolvo);
}


void delete_by_index(void) {
	if (kolvo == 0) {
		printf("\nМассив пуст, удалять нечего!\n");
		return;
	}

	int index = 0;
	printf("\nУдаление сотрудника по индексу\n");
	printf("Введите индекс (0-%d): ", kolvo - 1);
	scanf("%d", &index);

	if (index < 0 || index >= kolvo) {
		printf("Неверный индекс!\n");
		return;
	}

	printf("\nУдаляется: %s\n", employees[index].full_name);

	for (int i = index; i < kolvo - 1; i++) {
		employees[i] = employees[i + 1];
	}

	kolvo--;

	printf("Сотрудник удален! (осталось: %d/%d)\n", kolvo, capacity);
}

void save_to_file(const char* filename) {
	FILE* file = fopen(filename, "wb");

	if (file == NULL) {
		printf("Ошибка открытия файла для записи!\n");
		return;
	}
	fwrite(&kolvo, sizeof(int), 1, file);
	fwrite(&capacity, sizeof(int), 1, file);
	if (kolvo > 0) {
		fwrite(employees, sizeof(Employee), kolvo, file);
	}

	fclose(file);
	printf("Данные сохранены в файл '%s' (%d сотрудников)\n", filename, kolvo);
}


void load_from_file(const char* filename) {
	FILE* file = fopen(filename, "rb");

	if (file == NULL) {
		printf("Файл '%s' не найден. Начинаем с пустого массива.\n", filename);
		return;
	}

	if (employees != NULL) {
		free(employees);
	}

	fread(&kolvo, sizeof(int), 1, file);
	fread(&capacity, sizeof(int), 1, file);

	if (capacity > 0) {
		employees = (Employee*)malloc(capacity * sizeof(Employee));

		if (employees == NULL) {
			printf("Ошибка выделения памяти!\n");
			fclose(file);
			kolvo = 0;
			capacity = 0;
			return;
		}

		if (kolvo > 0) {
			fread(employees, sizeof(Employee), kolvo, file);
		}
	}
	else {
		employees = NULL;
	}

	fclose(file);
	printf("Данные загружены из файла '%s' (%d сотрудников, вместимость %d)\n",
		filename, kolvo, capacity);
}
