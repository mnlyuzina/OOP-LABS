#include <string>
#include <vector>
#include <memory>
#include <map>

// Координаты объекта
struct Position {
    int x;
    int y;
};

// Базовый класс NPC
class NPC {
public:
    virtual ~NPC() = default;
    virtual std::string getType() const = 0;
    virtual std::string getName() const = 0;
    virtual Position getPosition() const = 0;
    virtual void setPosition(int x, int y) = 0;
};

// Конкретные классы NPC
class Knight : public NPC {
    std::string name;
    Position position;
public:
    Knight(const std::string& name, int x, int y);
    std::string getType() const override;
    std::string getName() const override;
    Position getPosition() const override;
    void setPosition(int x, int y) override;
};

class Druid : public NPC {
    std::string name;
    Position position;
public:
    Druid(const std::string& name, int x, int y);
    std::string getType() const override;
    std::string getName() const override;
    Position getPosition() const override;
    void setPosition(int x, int y) override;
};

class Elf : public NPC {
    std::string name;
    Position position;
public:
    Elf(const std::string& name, int x, int y);
    std::string getType() const override;
    std::string getName() const override;
    Position getPosition() const override;
    void setPosition(int x, int y) override;
};

// Factory
class NPCFactory {
public:
    static std::shared_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y);
};

// Observer
class Observer {
public:
    virtual ~Observer() = default;
    virtual void onNPCDefeated(const std::string& message) = 0;
};

class ConsoleObserver : public Observer {
public:
    void onNPCDefeated(const std::string& message) override;
};

class FileObserver : public Observer {
public:
    void onNPCDefeated(const std::string& message) override;
};

// Visitor
class CombatVisitor {
public:
    void battle(std::vector<std::shared_ptr<NPC>>& npcs, std::vector<std::shared_ptr<Observer>>& observers, int range);
};

// Класс редактора
class NPCEditor {
    std::vector<std::shared_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<Observer>> observers;
public:
    void addNPC(const std::string& type, const std::string& name, int x, int y);
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    void printNPCs() const;
    void startCombat(int range);
    void addObserver(std::shared_ptr<Observer> observer);

    size_t getNPCCount() const;
    std::string getNPCName(size_t index) const;
};
