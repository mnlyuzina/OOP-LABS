#include "NPCEditor.h"
#include <iostream>
#include <memory>

int main() {
    NPCEditor editor;

    // Добавляем наблюдателей
    auto consoleObserver = std::make_shared<ConsoleObserver>();
    auto fileObserver = std::make_shared<FileObserver>();
    editor.addObserver(consoleObserver);
    editor.addObserver(fileObserver);

    while (true) {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить NPC\n";
        std::cout << "2. Показать всех NPC\n";
        std::cout << "3. Сохранить NPC в файл\n";
        std::cout << "4. Загрузить NPC из файла\n";
        std::cout << "5. Запустить боевой режим\n";
        std::cout << "6. Выход\n";
        std::cout << "Выберите опцию: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string type, name;
            int x, y;
            std::cout << "Введите тип NPC (Knight, Druid, Elf): ";
            std::cin >> type;
            std::cout << "Введите имя NPC: ";
            std::cin >> name;
            std::cout << "Введите координаты x и y (0-500): ";
            std::cin >> x >> y;

            if (x < 0 || x > 500 || y < 0 || y > 500) {
                std::cout << "Координаты должны быть в диапазоне от 0 до 500. Попробуйте снова.\n";
                continue;
            }

            try {
                editor.addNPC(type, name, x, y);
                std::cout << "NPC добавлен успешно.\n";
            } catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << "\n";
            }

        } else if (choice == 2) {
            editor.printNPCs();
        } else if (choice == 3) {
            std::string filename;
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            editor.saveToFile(filename);
            std::cout << "NPC сохранены в файл " << filename << ".\n";
        } else if (choice == 4) {
            std::string filename;
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> filename;
            editor.loadFromFile(filename);
            std::cout << "NPC загружены из файла " << filename << ".\n";
        } else if (choice == 5) {
            int range;
            std::cout << "Введите дальность боя: ";
            std::cin >> range;
            editor.startCombat(range);
        } else if (choice == 6) {
            std::cout << "Выход из программы.\n";
            break;
        } else {
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
