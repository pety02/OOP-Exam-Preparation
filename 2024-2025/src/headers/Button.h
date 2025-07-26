//
// Created by User on 7/26/2025.
//

#ifndef BUTTON_H
#define BUTTON_H
#pragma once

#include "Control.h"
#include "Panel.h"
#include <functional>

/*

Button – Това е контрола, която извършва дадено действие. Това действие се подава като функционален обект или указател към
функция при създаване на бутон. Действието може да е празно и не се записва при save, както и не се прочита при load. Бутонът
задължително трябва да е част от панел, като тази информация също не се записва/прочита. Трябва да има функционален оператор,
който да изпълнява съответната функция, подавайки като аргумент името на бутона и указател към панела, в който се намира той.
Настройките на бутон са името му, следвано от информация дали има асоциирано или не действие.

*/

typedef bool (*Func)(char*, Panel*);

class Button : public Control {
private:
    Panel* parentPanel;  
    std::function<void(const char*, Panel*)> action;


public:
    Button();
    Button(const char* const name, const char* const helpMessage, bool enabled,
           Func action = nullptr);
    Button(const Button&);
    Button(Button&&) noexcept;
    Button& operator=(const Button&);
    Button& operator=(Button&&) noexcept;
    ~Button() override;

    void print() const override;
    void store(const char* const) const override;
    void load(const char* const) override;
    const char* const settings() const override;
    void operator()();

    const Panel* getParentPanel() const;
    const std::function<void(const char*, Panel*)> getAction() const;

    void setParentPanel(Panel*);
};

#endif // BUTTON_H