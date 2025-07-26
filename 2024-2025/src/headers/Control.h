//
// Created by User on 7/26/2025.
//

#ifndef CONTROL_H
#define CONTROL_H
#pragma once

/*

Основа на йерархията ще е абстрактният клас Control, който трябва да притежава следните свойства:
id – уникален числен идентификатор. Той се задава при създаване на обект и повече не трябва да може да се променя. При
създаване на копие трябва да се запази;
name – символен низ с произволна дължина (не може да е празен);
helpMessage – символен низ с произволна дължина (може да е празен);
enabled - булева стойност дали е активна.
За всички наследници позволете промяна на всяко поле (когато не е указано друго), като за всички полета без enabled това се
допуска само ако контролата е активна;
Всяка контрола трябва да може да изведе информация за себе си на екрана (print), да се запише в двоичен файл (store) и да се
прочете от така записани стойности в двоичен файл (load). При четене id не се променя;
Една контрола трябва да може да дава информация за избраните опции (settings) – това е символен низ, който описва какви са
настройките за конкретните контроли

*/

class Control {
private:
static unsigned ID_SEQ;
const unsigned id;
char* name;
char* helpMessage;
bool enabled;

virtual void copy(const Control&);
virtual void destroy();

public:
  Control();
  Control(const char* const, const char* const, bool);
  Control(const Control&);
  Control(Control&&) noexcept;
  virtual ~Control();

  virtual void print() const = 0;
  virtual void store(const char* const) const = 0;
  virtual void load(const char* const) = 0;
  virtual const char* const settings() const = 0;

  const unsigned getID() const;
  const char* const getName() const;
  const char* const getHelpMessage() const;
  bool isEnabled() const;

  virtual void setName(const char* const);
  virtual void setHelpMessage(const char* const);
  virtual void setEnabled(bool);
  Control* clone() const;
};

unsigned Control::ID_SEQ = 0;

#endif //CONTROL_H