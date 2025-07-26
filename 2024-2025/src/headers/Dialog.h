//
// Created by User on 7/26/2025.
//

#ifndef DIALOG_H
#define DIALOG_H

#include "Panel.h"

/*

Реализирайте клас Dialog, който притежава един Panel, в който може да има произволен брой произволни контроли.


*/

class Dialog final : public Control {
private:
  Panel panel;

public:
  Dialog();
  Dialog(const char* const, const char* const, bool, const Panel&);
  Dialog(const Dialog&);
  Dialog(Dialog&&) noexcept;
  Dialog& operator=(const Dialog&);
  Dialog& operator=(Dialog&&) noexcept;
  ~Dialog() override;

  void print() const override;
  void store(const char* const) const override;
  void load(const char* const) override;
  const char* const settings() const override;

  const Panel& getPanel() const;

  void setPanel(const Panel&);
};

#endif //DIALOG_H