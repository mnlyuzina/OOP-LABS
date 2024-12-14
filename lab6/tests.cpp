#include <gtest/gtest.h>
#include "NPCEditor.h"
#include <memory>
#include <sstream>


TEST(NPCEditorTest, CreateNPC) {
    NPCEditor editor;
    editor.addNPC("Knight", "Lancelot", 100, 200);
    editor.addNPC("Druid", "Merlin", 300, 400);
    editor.addNPC("Elf", "Legolas", 500, 500);

    ASSERT_EQ(editor.getNPCCount(), 3);
    ASSERT_EQ(editor.getNPCName(0), "Lancelot");
    ASSERT_EQ(editor.getNPCName(1), "Merlin");
    ASSERT_EQ(editor.getNPCName(2), "Legolas");
}


TEST(NPCEditorTest, SaveLoadNPC) {
    NPCEditor editor;
    editor.addNPC("Knight", "Lancelot", 100, 200);
    editor.addNPC("Druid", "Merlin", 300, 400);
    editor.addNPC("Elf", "Legolas", 500, 500);

    std::string filename = "test_npcs.txt";
    editor.saveToFile(filename);

    NPCEditor loadedEditor;
    loadedEditor.loadFromFile(filename);

    ASSERT_EQ(loadedEditor.getNPCCount(), 3);
    ASSERT_EQ(loadedEditor.getNPCName(0), "Lancelot");
    ASSERT_EQ(loadedEditor.getNPCName(1), "Merlin");
    ASSERT_EQ(loadedEditor.getNPCName(2), "Legolas");
}


TEST(NPCEditorTest, Combat) {
    NPCEditor editor;
    editor.addNPC("Knight", "Lancelot", 100, 200);
    editor.addNPC("Elf", "Legolas", 150, 250);
    editor.addNPC("Druid", "Merlin", 300, 400);
    editor.addNPC("Druid", "Gandalf", 350, 450);

    auto consoleObserver = std::make_shared<ConsoleObserver>();
    auto fileObserver = std::make_shared<FileObserver>();
    editor.addObserver(consoleObserver);
    editor.addObserver(fileObserver);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    editor.startCombat(100);

    std::cout.rdbuf(old);

    std::string output = buffer.str();
    ASSERT_TRUE(output.find("Legolas defeated by Lancelot") != std::string::npos);
    ASSERT_TRUE(output.find("Both druids defeated each other") != std::string::npos);
}