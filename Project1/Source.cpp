#include <iostream> 

using namespace std; 

// ���������� ����� Player
class Player {
private:
    int hp;              
    int magic_power;     
    int stamina;         
    double magic_damage; 
    double physical_damage; 

public:
    // ����������� ��� ������������� �����
    Player(int hp, int magic_power, int stamina, double magic_damage, double physical_damage)
        : hp(hp), magic_power(magic_power), stamina(stamina), magic_damage(magic_damage), physical_damage(physical_damage) {}

    // ����� ��� ��������� �������� �����
    void setValues(int hp, int magic_power, int stamina, double magic_damage, double physical_damage) {
        this->hp = hp;
        this->magic_power = magic_power;
        this->stamina = stamina;
        this->magic_damage = magic_damage;
        this->physical_damage = physical_damage;
    }

    // ����� ��� ��������� �������� ��������� ������
    void viewStatus() const {
        cout << "HP: " << hp << "\nMagic Power: " << magic_power
            << "\nStamina: " << stamina << "\nMagic Damage: " << magic_damage
            << "\nPhysical Damage: " << physical_damage << endl;
    }

    // ����� ��� ������� �������� ������
    void calculateCoolness() const {
        // �������� �� ������� �� ����
        if (stamina == 0) {
            cout << "������: stamina �� ����� ���� �������." << endl;
            return;
        }
        if (magic_power == 0) {
            cout << "������: magic_power �� ����� ���� �������." << endl;
            return;
        }
        if (hp == 0) {
            cout << "������: hp �� ����� ���� �������." << endl;
            return;
        }

        // ������ ��������
        double coolness = (static_cast<double>(hp) * magic_power) / stamina +
            (static_cast<double>(hp) * stamina) / magic_power -
            (static_cast<double>(stamina) * magic_power) / hp;

        cout << "�������� ������: " << coolness << endl;
    }

    // ����� ��� ������ �����
    void displayDamage() const {
        // ������ ����������� � ����������� �����
        double magic_damage_output = (magic_damage * magic_power) - stamina;
        double physical_damage_output = (physical_damage * stamina) + hp - magic_power;

        cout << "���������� ����: " << magic_damage_output << endl;
        cout << "���������� ����: " << physical_damage_output << endl;
    }
};

// �������� �������
int main() {
    setlocale(LC_ALL, "Russian");
    // ������� ������ ������ � ���������� ����������
    Player player(100, 50, 25, 30.5, 20.5);

    // ���������� ������ ������ � �������
    player.viewStatus();        // ������� ������� ���������
    player.calculateCoolness(); // ������������ �������� ������
    player.displayDamage();     // ������� ����

    // ������������� ����� ��������
    player.setValues(0, 50, 25, 30.5, 20.5); // ������������� hp � 0, ����� ��������� ��������� ������
    player.calculateCoolness(); // ��������� ��������� ������

    return 0; // ��������� ���������
}
