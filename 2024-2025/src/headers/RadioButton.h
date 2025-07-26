//
// Created by User on 7/26/2025.
//

#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H
#pragma once

#include "Label.h"

/*

RadioButon - Това е контрола, която се състои от не празен брой етикети (Label), които са и не-повече от 16. Позволява избор на не
повече от един от тях. При създаване няма избран. Избор се прави чрез функционален оператор с аргумент идентификатора на
съответния етикет. Той трябва да връща булева стойност в зависимост дали дадения идентификатор е валиден или не. Стойност на
settings е името на избрания етикет, или празен низ, ако няма избран. Добавете методи за добавяне на етикет и премахване на етикет
по неговия идентификатор, както и получаване на достъп до етикет по индекса в списъка. Следете да няма повторения на
идентификатори.

*/

class RadioButton final : public Control {
private:
  const static int LABEL_MAX_COUNT = 16;
  Label* labels[RadioButton::LABEL_MAX_COUNT];
  int size;
  int selected;

public:
  RadioButton();
  RadioButton(const char* const, const char* const, bool, const Label* labels);
  RadioButton(const RadioButton&);
  RadioButton(RadioButton&&) noexcept;
  RadioButton& operator=(const RadioButton&);
  RadioButton& operator=(RadioButton&&) noexcept;
  ~RadioButton() override;

  void print() const override;
  void store(const char* const) const override;
  void load(const char* const) override;
  const char* const settings() const override;

  // TODO: add getters and setters

  bool operator()(int) const;
  void addLabel(const Label&);
  void removeLabel(int);
  const Label& getLabelByIdx(int) const;
};

#endif //RADIOBUTTON_H