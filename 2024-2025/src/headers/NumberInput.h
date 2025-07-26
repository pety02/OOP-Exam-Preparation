//
// Created by User on 7/26/2025.
//

#ifndef NUMBERINPUT_H
#define NUMBERINPUT_H
#pragma once

#include "Control.h"

/*

NumberInput – Това е контрола, която съхранява целочислена стойност. При конструиране трябва да се подават начална, максимална
и минимална стойност, която може да се получи. Нейните настройки са символно представяне на тази стойност. Реализирайте
оператори ++, -- , + и – с число, които променят съответно стойността, следейки да не излезе от определения диапазон. Добавете
оператор за преобразуване към int, който дава стойността на контролата.

*/

class NumberInput final : public Control {
private:
  int initialValue;
  int minValue;
  int maxValue;
  int value;
  
public:
  NumberInput();
  NumberInput(const char* const, const char* const, bool, int, int, int);
  NumberInput(const NumberInput&);
  NumberInput(NumberInput&&) noexcept;
  NumberInput& operator=(const NumberInput&);
  NumberInput& operator=(NumberInput&&) noexcept;
  NumberInput operator+(int);
  NumberInput& operator++(int);
  NumberInput operator-(int);
  NumberInput& operator--(int);
  operator int() const;
  ~NumberInput() override;

  void print() const override;
  void store(const char* const) const override;
  void load(const char* const) override;
  const char* const settings() const override;

  void setInitialValue(int);
  void setMinValue(int);
  void setMaxValue(int);
  void setValue(int);

  int getInitialValue() const;
  int getMinValue() const;
  int getMaxValue() const;
  int getValue() const;
};

#endif //NUMBERINPUT_H