/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 LibrePCB Developers, see AUTHORS.md for contributors.
 * https://librepcb.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBREPCB_EDITOR_STROKETEXTPROPERTIESDIALOG_H
#define LIBREPCB_EDITOR_STROKETEXTPROPERTIESDIALOG_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include <QtCore>
#include <QtWidgets>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {

class BI_StrokeText;
class Layer;
class LengthUnit;
class StrokeFont;
class StrokeText;

namespace editor {

class UndoStack;

namespace Ui {
class StrokeTextPropertiesDialog;
}

/*******************************************************************************
 *  Class StrokeTextPropertiesDialog
 ******************************************************************************/

/**
 * @brief The StrokeTextPropertiesDialog class
 */
class StrokeTextPropertiesDialog final : public QDialog {
  Q_OBJECT

public:
  // Constructors / Destructor
  StrokeTextPropertiesDialog() = delete;
  StrokeTextPropertiesDialog(const StrokeTextPropertiesDialog& other) = delete;
  StrokeTextPropertiesDialog(StrokeText& text, UndoStack& undoStack,
                             const QSet<const Layer*>& layers,
                             const LengthUnit& lengthUnit,
                             const QString& settingsPrefix,
                             QWidget* parent = nullptr) noexcept;
  StrokeTextPropertiesDialog(BI_StrokeText& text, UndoStack& undoStack,
                             const QSet<const Layer*>& layers,
                             const LengthUnit& lengthUnit,
                             const QString& settingsPrefix,
                             QWidget* parent = nullptr) noexcept;
  ~StrokeTextPropertiesDialog() noexcept;

  // Setters
  void setReadOnly(bool readOnly) noexcept;

  // Operator Overloadings
  StrokeTextPropertiesDialog& operator=(const StrokeTextPropertiesDialog& rhs) =
      delete;

private:  // Methods
  StrokeTextPropertiesDialog(StrokeText* libObj, BI_StrokeText* boardObj,
                             UndoStack& undoStack,
                             const QSet<const Layer*>& layers,
                             const LengthUnit& lengthUnit,
                             const QString& settingsPrefix,
                             QWidget* parent = nullptr) noexcept;
  template <typename T>
  void load(const T& obj, const StrokeFont& font) noexcept;
  void on_buttonBox_clicked(QAbstractButton* button);
  bool applyChanges() noexcept;
  template <typename T>
  void applyChanges(T& cmd);

private:  // Data
  StrokeText* mLibraryObj;
  BI_StrokeText* mBoardObj;
  UndoStack& mUndoStack;
  QScopedPointer<Ui::StrokeTextPropertiesDialog> mUi;
};

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace editor
}  // namespace librepcb

#endif
