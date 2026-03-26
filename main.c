#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "data.h"

#define SAVE_FILE "employees.dat"

int main() {
	setlocale(LC_ALL, ".UTF8");

	printf("\nУправление сотрудниками\n");
	load_from_file(SAVE_FILE);
	if (employees == NULL) {
		employees = (Employee*)malloc(3 * sizeof(Employee));
		if (employees == NULL) {
			printf("Ошибка выделения начальной памяти!\n");
			return 1;
		}
		capacity = 3;
		kolvo = 0;
		printf("Начальная вместимость: %d элементов\n\n", capacity);
	}

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
		printf("8 - Сортировка массива\n");
		printf("9 - Вставить сотрудника на позицию\n");
		printf("10 - Удалить сотрудника по индексу\n");
		printf("11 - Сохранить в файл\n");
		printf("12 - Загрузить из файла\n");
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
		case 8:
			sort_employees();
			break;
		case 9:
			insert_at_position();
			break;
		case 10:
			delete_by_index();
			break;
		case 11:
			save_to_file(SAVE_FILE);
			break;
		case 12:
			load_from_file(SAVE_FILE);
			break;
		case 0:
			printf("\nАвтосохранение перед выходом...\n");
			save_to_file(SAVE_FILE);
			printf("Очистка памяти...\n");
			clear_all_memory();
			printf("До свидания!\n");
			return 0;
		default:
			printf("\nНеверный выбор!\n");
		}
	}

	return 0;
}