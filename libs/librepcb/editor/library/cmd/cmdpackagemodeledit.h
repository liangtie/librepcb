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

#ifndef LIBREPCB_EDITOR_CMDPACKAGEMODELEDIT_H
#define LIBREPCB_EDITOR_CMDPACKAGEMODELEDIT_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "../../cmd/cmdlistelementsswap.h"

#include <librepcb/core/library/pkg/packagemodel.h>

#include <QtCore>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {

class Package;

namespace editor {

/*******************************************************************************
 *  Class CmdPackageModelEdit
 ******************************************************************************/

/**
 * @brief The CmdPackageModelEdit class
 */
class CmdPackageModelEdit : public UndoCommand {
public:
  // Constructors / Destructor
  CmdPackageModelEdit() = delete;
  CmdPackageModelEdit(const CmdPackageModelEdit& other) = delete;
  explicit CmdPackageModelEdit(Package& package, PackageModel& model) noexcept;
  virtual ~CmdPackageModelEdit() noexcept;

  // Setters
  void setName(const ElementName& name) noexcept;
  void setStepContent(const QByteArray& content) noexcept;

  // Operator Overloadings
  CmdPackageModelEdit& operator=(const CmdPackageModelEdit& rhs) = delete;

protected:  // Methods
  /// @copydoc ::librepcb::editor::UndoCommand::performExecute()
  virtual bool performExecute() override;

  /// @copydoc ::librepcb::editor::UndoCommand::performUndo()
  virtual void performUndo() override;

  /// @copydoc ::librepcb::editor::UndoCommand::performRedo()
  virtual void performRedo() override;

private:  // Data
  Package& mPackage;
  PackageModel& mModel;

  ElementName mOldName;
  ElementName mNewName;
  QByteArray mOldStepContent;
  QByteArray mNewStepContent;
};

/*******************************************************************************
 *  Undo Commands
 ******************************************************************************/

using CmdPackageModelsSwap =
    CmdListElementsSwap<PackageModel, PackageModelListNameProvider,
                        PackageModel::Event>;

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace editor
}  // namespace librepcb

#endif
