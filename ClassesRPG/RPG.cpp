#include <math.h>
#include <locale>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>

#define MAX_LEVEL 15
class Character {
public:
	int hp;
	int armor;
	int dodge;
};
class Engine {
public:
	int arrows;
	void attack(Character& target, int damage, oil used = nothing);
	int getDistance(const Character& target);
};
class oil {};
class Weapon : public Engine{
public:
	std::string name;
	bool type; // так-как заявлено два класса
	int level;
	float damage;
	Weapon(std::string _name = "NewWeapon", bool _type = 0, int _level = 1, float _damage = 5) : name(_name), type(_type), level(_level), damage(_damage) {}
	Weapon(const Weapon& copy) : name(copy.name), type(copy.type), level(copy.level), damage(copy.damage) {}
};
class Crossbow : public Weapon {
public:
	float reloadTime;
	int range;
	Crossbow(std::string _name = "NewWeapon", bool _type = 0, int _level = 1, float _reloadTime = 3000, int _range = 10, float _damage = 2) :
		Weapon(_name,_type,_level,_damage), reloadTime(_reloadTime), range(_range) {}
	Crossbow(const Crossbow& copy) : Weapon(copy.name, copy.type, copy.level, copy.damage), reloadTime(copy.reloadTime), range(copy.range) {}
	void use(Character& target) {
		if (arrows > 0) {
			arrows -= 1;
			if (getDistance(target) <= range) {
				attack(target, damage);
			}
			Sleep((int)reloadTime);
		}
	}
	void levelUp() {
		if (level < MAX_LEVEL) {
			level += 1;
			reloadTime *= 0.9;
			damage *= 1.1;
		}
	}
	Crossbow& operator=(const Crossbow& right) {
		this->range = right.range;
		this->reloadTime = right.reloadTime;
		this->name = right.name;
		this->type = right.type;
		this->level = right.level;
		this->damage = right.damage;
	}
	bool operator==(const Crossbow& right) {
		if ((this->damage) * (1000/(this -> reloadTime)) * 0.1 * (this -> range) == right.damage*1000/right.reloadTime*0.1*right.range) {
			return 1;
		}
		return 0;
	}
	bool operator<(const Crossbow& right) {
		if ((this->damage) * (1000 / (this->reloadTime)) * 0.1 * (this->range) < right.damage * 1000 / right.reloadTime * 0.1 * right.range) {
			return 1;
		}
		return 0;
	}
	bool operator>(const Crossbow& right) {
		if ((this->damage) * (1000 / (this->reloadTime)) * 0.1 * (this->range) > right.damage * 1000 / right.reloadTime * 0.1 * right.range) {
			return 1;
		}
		return 0;
	}
	std::ostream& operator<<(std::ostream& out) {
		return out << "Crossbow name: " << this->name << "\n" << "Класс: " << ((this->type) == 1 ? "Воин\n" : "Ловкач\n") << "Уровень: " << this->level << "\n" << "Урон:" << this->damage << "\n" << "Время перезарядки: " << (this->reloadTime)/1000 << " сек \n" << "Дальность: " << this -> range << "\n";
	}
};
class Sword : public Weapon {
public:
	oil used;
	Sword(std::string _name = "NewWeapon", bool _type = 0, int _level = 1, float _damage = 2, oil& _used) :
		Weapon(_name, _type, _level, _damage), used(_used) {}
	Sword(const Sword& copy) : Weapon(copy.name, copy.type, copy.level, copy.damage), used(copy.used) {}
	void use(Character& target) {
			if (getDistance(target) <= 1) {
				attack(target, damage, used);
			}
			Sleep(500);
	}
	void levelUp() {
		if (level < MAX_LEVEL) {
			level += 1;
			damage *= 1.2;
		}
	}
	Sword& operator=(const Sword& right) {
		this->used = right.used;
		this->name = right.name;
		this->type = right.type;
		this->level = right.level;
		this->damage = right.damage;
	}
	bool operator==(const Sword& right) {
		if (this->damage == right.damage) {
			return 1;
		}
		return 0;
	}
	bool operator<(const Sword& right) {
		if (this->damage < right.damage) {
			return 1;
		}
		return 0;
	}
	bool operator>(const Sword& right) {
		if (this->damage > right.damage) {
			return 1;
		}
		return 0;
	}
	std::ostream& operator<<(std::ostream& out) {
		return out << "Sword name: " << this->name << "\n" << "Класс: " << ((this->type) == 1 ? "Воин\n": "Ловкач\n") << "Уровень: " << this->level << "\n" << "Урон:" << this->damage << "\n";
	}
};