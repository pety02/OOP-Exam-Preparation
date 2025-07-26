//
// Created by User on 7/26/2025.
//

#ifndef PANEL_H
#define PANEL_H
#pragma once

#include "Control.h"

/*

Panel – Това е контрола, която групира множество други контроли. Трябва да поддържа оператори + и – за добавяне и премахване на
контрола и оператор за индексиране за получаване на контрола по нейния идентификатор. Следете да няма повторения. Настройката
на панела представлява конкатенация на настройките на всички негови контроли разделени със символа ‘|’. При промяна на
активността на панел (enabled) трябва съответно да се промени активността на всички контроли в него.

*/

class Panel final : public Control {
private:
  // TODO: change fields name to be more comprehensive
  int maxCapacity;
  int currControlsIndex;
  Control** controls;

  virtual void copy(const Control&) override;
  virtual void destroy() override;

public:
    Panel();
    Panel(const char* const, const char* const, bool, int, int);
    Panel(const Panel&);
    Panel(Panel&&) noexcept;
    Panel& operator=(const Panel&);
    Panel& operator=(Panel&&) noexcept;
    Panel& operator+(const Control*&);
    Panel& operator-(const Control*&);
    Control& operator[](int);
    const Control& operator[](int) const;
    ~Panel() override;

    void print() const override;
    void store(const char* const) const override;
    void load(const char* const) override;
    const char* const settings() const override;

    // TODO: Change getters and setters names

    int getMaxCapacity() const;
    int getCurrControlsIndex() const;
    const Control* getControls() const;

    void setCurrControlsIndex(int);
    void setControls(const Control*);
};

#endif //PANEL_H