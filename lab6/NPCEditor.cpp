#include "NPCEditor.h"
#include <iostream>
#include <fstream>
#include <cmath>

// Реализация классов NPC
Knight::Knight(const std::string& name, int x, int y) : name(name), position({x, y}) {}
std::string Knight::getType() const { return "Knight"; }
std::string Knight::getName() const { return name; }
Position Knight::getPosition() const { return position; }
void Knight::setPosition(int x, int y) { position = {x, y}; }

Druid::Druid(const std::string& name, int x, int y) : name(name), position({x, y}) {}
std::string Druid::getType() const { return "Druid"; }
std::string Druid::getName() const { return name; }
Position Druid::getPosition() const { return position; }
void Druid::setPosition(int x, int y) { position = {x, y}; }

Elf::Elf(const std::string& name, int x, int y) : name(name), position({x, y}) {}
std::string Elf::getType() const { return "Elf"; }
std::string Elf::getName() const { return name; }
Position Elf::getPosition() const { return position; }
void Elf::setPosition(int x, int y) { position = {x, y}; }

// Реализация NPCFactory
std::shared_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Knight") {
        return std::make_shared<Knight>(name, x, y);
    } else if (type == "Druid") {
        return std::make_shared<Druid>(name, x, y);
    } else if (type == "Elf") {
        return std::make_shared<Elf>(name, x, y);
    }
    throw std::invalid_argument("Unknown NPC type");
}

// Реализация Observer
void ConsoleObserver::onNPCDefeated(const std::string& message) {
    std::cout << message << std::endl;
}

void FileObserver::onNPCDefeated(const std::string& message) {
    std::ofstream log("log.txt", std::ios::app);
    if (log.is_open()) {
        log << message << std::endl;
    }
}

// Реализация CombatVisitor
void CombatVisitor::battle(std::vector<std::shared_ptr<NPC>>& npcs, std::vector<std::shared_ptr<Observer>>& observers, int range) {
    for (size_t i = 0; i < npcs.size(); ++i) {
        for (size_t j = i + 1; j < npcs.size(); ++j) {
            auto pos1 = npcs[i]->getPosition();
            auto pos2 = npcs[j]->getPosition();
            int distance = std::sqrt(std::pow(pos1.x - pos2.x, 2) + std::pow(pos1.y - pos2.y, 2));

            if (distance <= range) {
                std::string result;
                if ((npcs[i]->getType() == "Knight" && npcs[j]->getType() == "Elf") ||
                    (npcs[j]->getType() == "Knight" && npcs[i]->getType() == "Elf")) {
                    result = npcs[j]->getName() + " defeated by " + npcs[i]->getName();
                } else if ((npcs[i]->getType() == "Elf" && npcs[j]->getType() == "Druid") ||
                           (npcs[j]->getType() == "Elf" && npcs[i]->getType() == "Druid")) {
                    result = npcs[i]->getName() + " defeated by " + npcs[j]->getName();
                } else if (npcs[i]->getType() == "Druid" && npcs[j]->getType() == "Druid") {
                    result = "Both druids defeated each other";
                }
                for (auto& observer : observers) {
                    observer->onNPCDefeated(result);
                }
                npcs.erase(npcs.begin() + j);
                npcs.erase(npcs.begin() + i);
                --i;
                break;
            }
        }
    }
}

// Реализация NPCEditor
void NPCEditor::addNPC(const std::string& type, const std::string& name, int x, int y) {
    npcs.push_back(NPCFactory::createNPC(type, name, x, y));
}

void NPCEditor::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& npc : npcs) {
        file << npc->getType() << " " << npc->getName() << " " << npc->getPosition().x << " " << npc->getPosition().y << std::endl;
    }
}

void NPCEditor::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string type, name;
    int x, y;
    while (file >> type >> name >> x >> y) {
        addNPC(type, name, x, y);
    }
}

void NPCEditor::printNPCs() const {
    for (const auto& npc : npcs) {
        std::cout << npc->getType() << " " << npc->getName() << " (" << npc->getPosition().x << ", " << npc->getPosition().y << ")" << std::endl;
    }
}

void NPCEditor::startCombat(int range) {
    CombatVisitor visitor;
    visitor.battle(npcs, observers, range);
}

void NPCEditor::addObserver(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

size_t NPCEditor::getNPCCount() const {
    return npcs.size();
}

std::string NPCEditor::getNPCName(size_t index) const {
    if (index < npcs.size()) {
        return npcs[index]->getName();
    }
    return "";
}
