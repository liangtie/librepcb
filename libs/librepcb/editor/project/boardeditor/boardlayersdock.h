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

#ifndef LIBREPCB_EDITOR_BOARDLAYERSDOCK_H
#define LIBREPCB_EDITOR_BOARDLAYERSDOCK_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "../../graphics/graphicslayer.h"

#include <QtCore>
#include <QtWidgets>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {
namespace editor {

namespace Ui {
class BoardLayersDock;
}

/*******************************************************************************
 *  Class BoardLayersDock
 ******************************************************************************/

/**
 * @brief The BoardLayersDock class
 */
class BoardLayersDock final : public QDockWidget {
  Q_OBJECT

public:
  // Constructors / Destructor
  BoardLayersDock() = delete;
  BoardLayersDock(const BoardLayersDock& other) = delete;
  explicit BoardLayersDock(const IF_GraphicsLayerProvider& lp) noexcept;
  ~BoardLayersDock() noexcept;

  // Operator Overloadings
  BoardLayersDock& operator=(const BoardLayersDock& rhs) = delete;

signals:
  void layersVisibilityChanged();

private slots:
  void on_listWidget_itemChanged(QListWidgetItem* item);
  void on_btnTop_clicked();
  void on_btnBottom_clicked();
  void on_btnTopBottom_clicked();
  void on_btnAll_clicked();
  void on_btnNone_clicked();

private:
  // Private Methods
  void layerEdited(const GraphicsLayer& layer,
                   GraphicsLayer::Event event) noexcept;
  void updateListWidget() noexcept;
  void setVisibleLayers(const QList<QString>& layers) noexcept;
  QList<QString> getCommonLayers() const noexcept;
  QList<QString> getTopLayers() const noexcept;
  QList<QString> getBottomLayers() const noexcept;
  QList<QString> getAllLayers() const noexcept;

  // General
  const IF_GraphicsLayerProvider& mLayerProvider;
  QScopedPointer<Ui::BoardLayersDock> mUi;
  bool mUpdateScheduled;

  // Slots
  GraphicsLayer::OnEditedSlot mOnLayerEditedSlot;
};

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace editor
}  // namespace librepcb

#endif
