#include <iostream> 

using namespace std; 

// Определяем класс Player
class Player {
private:
    int hp;              
    int magic_power;     
    int stamina;         
    double magic_damage; 
    double physical_damage; 

public:
    // Конструктор для инициализации полей
    Player(int hp, int magic_power, int stamina, double magic_damage, double physical_damage)
        : hp(hp), magic_power(magic_power), stamina(stamina), magic_damage(magic_damage), physical_damage(physical_damage) {}

    // Метод для установки значений полей
    void setValues(int hp, int magic_power, int stamina, double magic_damage, double physical_damage) {
        this->hp = hp;
        this->magic_power = magic_power;
        this->stamina = stamina;
        this->magic_damage = magic_damage;
        this->physical_damage = physical_damage;
    }

    // Метод для просмотра текущего состояния игрока
    void viewStatus() const {
        cout << "HP: " << hp << "\nMagic Power: " << magic_power
            << "\nStamina: " << stamina << "\nMagic Damage: " << magic_damage
            << "\nPhysical Damage: " << physical_damage << endl;
    }

    // Метод для расчета крутости игрока
    void calculateCoolness() const {
        // Проверка на деление на ноль
        if (stamina == 0) {
            cout << "Ошибка: stamina не может быть нулевым." << endl;
            return;
        }
        if (magic_power == 0) {
            cout << "Ошибка: magic_power не может быть нулевым." << endl;
            return;
        }
        if (hp == 0) {
            cout << "Ошибка: hp не может быть нулевым." << endl;
            return;
        }

        // Расчет крутости
        double coolness = (static_cast<double>(hp) * magic_power) / stamina +
            (static_cast<double>(hp) * stamina) / magic_power -
            (static_cast<double>(stamina) * magic_power) / hp;

        cout << "Крутость игрока: " << coolness << endl;
    }

    // Метод для вывода урона
    void displayDamage() const {
        // Расчет магического и физического урона
        double magic_damage_output = (magic_damage * magic_power) - stamina;
        double physical_damage_output = (physical_damage * stamina) + hp - magic_power;

        cout << "Магический урон: " << magic_damage_output << endl;
        cout << "Физический урон: " << physical_damage_output << endl;
    }
};

// Основная функция
int main() {
    setlocale(LC_ALL, "Russian");
    // Создаем объект игрока с начальными значениями
    Player player(100, 50, 25, 30.5, 20.5);

    // Используем прямой доступ к методам
    player.viewStatus();        // Выводим текущее состояние
    player.calculateCoolness(); // Рассчитываем крутость игрока
    player.displayDamage();     // Выводим урон

    // Устанавливаем новые значения
    player.setValues(0, 50, 25, 30.5, 20.5); // Устанавливаем hp в 0, чтобы проверить обработку ошибки
    player.calculateCoolness(); // Проверяем обработку ошибки

    return 0; // Завершаем программу
}
