#include <iostream>
#include <memory>

#include "Button.hpp"
#include "TextBox.hpp"
#include "Checkbox.hpp"
#include "LoginDialogMediator.hpp"

int main()
{
	std::unique_ptr<TextBox> usernameBox = std::make_unique<TextBox>("UsernameTextBox");
	std::unique_ptr<TextBox> passwordBox = std::make_unique<TextBox>("PasswordTextBox");
	std::unique_ptr<Checkbox> termsCheckbox = std::make_unique<Checkbox>("TermsCheckbox");
	std::unique_ptr<Button> submitButton = std::make_unique<Button>("SubmitButton");

	std::unique_ptr<LoginDialogMediator> mediator = std::make_unique<LoginDialogMediator>();

	mediator->SetComponents(usernameBox.get(), passwordBox.get(), termsCheckbox.get(), submitButton.get());

	std::cout << "Initial state: " << (submitButton->IsEnabled() ? "ENABLED" : "DISABLED") << std::endl;

	submitButton->Click();

	usernameBox->SetText("john.doe");

	std::cout << "After username: " << (submitButton->IsEnabled() ? "ENABLED" : "DISABLED") << std::endl;

	submitButton->Click();

	termsCheckbox->SetChecked(true);

	std::cout << "After terms checked: " << (submitButton->IsEnabled() ? "ENABLED" : "DISABLED") << std::endl;

	submitButton->Click();

	usernameBox->SetText("");

	submitButton->Click();

	return 0;
}