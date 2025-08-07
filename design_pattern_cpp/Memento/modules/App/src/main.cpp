#include <iostream>
#include <memory>

#include "Editor.hpp"
#include "EditorMemento.hpp"
#include "History.hpp"

int main()
{
    std::unique_ptr<Editor> editor = std::make_unique<Editor>("Initial text.");

    std::unique_ptr<History> history = std::make_unique<History>();

    std::cout << "\n--- Simulating Editor Operations ---" << std::endl;

    history->Push(editor->Save());

    editor->SetText("First modification.");
    history->Push(editor->Save());

    editor->SetText("Second modification.");

    std::cout << "\n--- Undoing ---" << std::endl;

    std::unique_ptr<EditorMemento> poppedMemento1 = history->Pop();
    if (poppedMemento1)
    {
        editor->Restore(poppedMemento1.get());
    }
    std::cout << "Current editor text: \"" << editor->GetText() << "\"" << std::endl;

    std::cout << "\n--- Undoing again ---" << std::endl;
    std::unique_ptr<EditorMemento> poppedMemento2 = history->Pop();
    if (poppedMemento2)
    {
        editor->Restore(poppedMemento2.get());
    }
    std::cout << "Current editor text: \"" << editor->GetText() << "\"" << std::endl;

    std::cout << "\n--- Trying to undo when no mementos left ---" << std::endl;
    std::unique_ptr<EditorMemento> poppedMemento3 = history->Pop();
    if (poppedMemento3)
    {
        editor->Restore(poppedMemento3.get());
    }
    std::cout << "Current editor text: \"" << editor->GetText() << "\"" << std::endl;

    std::cout << "\nProgram finished." << std::endl;

    return 0;
}