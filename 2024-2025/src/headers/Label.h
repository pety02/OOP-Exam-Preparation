//
// Created by User on 7/26/2025.
//

#ifndef LABEL_H
#define LABEL_H
#pragma once

#include "Control.h"

/*

Label – Тази контрола няма възможност да се променя от потребителя – веднъж зададени името и помощния текст остават
непроменими. За настройки връща винаги празен низ.


*/

class Label final : public Control {
private:
    void setName(const char* const) override {}
    void setHelpMessage(const char* const) override {}
    void setEnabled(bool) override {}

public:
    Label();
    Label(const char* const, const char* const, bool);
    Label(const Label&);
    Label(Label&&) noexcept;
    Label& operator=(const Label&);
    Label& operator=(Label&&) noexcept;
    ~Label() override;

    void print() const override;
    void store(const char*) const override;
    void load(const char*) override;
    const char* const settings() const override;
};

#endif //LABEL_H