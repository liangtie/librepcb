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

#ifndef LIBREPCB_EDITOR_CMDASSEMBLYVARIANTEDIT_H
#define LIBREPCB_EDITOR_CMDASSEMBLYVARIANTEDIT_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "../../cmd/cmdlistelementsswap.h"
#include "../../undocommand.h"

#include <librepcb/core/project/circuit/assemblyvariant.h>

#include <QtCore>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {

class Circuit;

namespace editor {

/*******************************************************************************
 *  Class CmdAssemblyVariantEdit
 ******************************************************************************/

/**
 * @brief The CmdAssemblyVariantEdit class
 */
class CmdAssemblyVariantEdit final : public UndoCommand {
public:
  // Constructors / Destructor
  CmdAssemblyVariantEdit() = delete;
  CmdAssemblyVariantEdit(const CmdAssemblyVariantEdit& other) = delete;
  explicit CmdAssemblyVariantEdit(Circuit& circuit,
                                  std::shared_ptr<AssemblyVariant> av) noexcept;
  ~CmdAssemblyVariantEdit() noexcept;

  // Setters
  void setName(const FileProofName& value) noexcept;
  void setDescription(const QString& value) noexcept;

  // Operator Overloadings
  CmdAssemblyVariantEdit& operator=(const CmdAssemblyVariantEdit& rhs) = delete;

private:  // Methods
  /// @copydoc ::librepcb::editor::UndoCommand::performExecute()
  bool performExecute() override;

  /// @copydoc ::librepcb::editor::UndoCommand::performUndo()
  void performUndo() override;

  /// @copydoc ::librepcb::editor::UndoCommand::performRedo()
  void performRedo() override;

private:  // Data
  Circuit& mCircuit;
  std::shared_ptr<AssemblyVariant> mAssemblyVariant;

  FileProofName mOldName;
  FileProofName mNewName;
  QString mOldDescription;
  QString mNewDescription;
};

/*******************************************************************************
 *  Undo Commands
 ******************************************************************************/

using CmdAssemblyVariantsSwap =
    CmdListElementsSwap<AssemblyVariant, AssemblyVariantListNameProvider,
                        AssemblyVariant::Event>;

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace editor
}  // namespace librepcb

#endif
