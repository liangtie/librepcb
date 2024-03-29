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

#ifndef LIBREPCB_CORE_PICKPLACECSVWRITER_H
#define LIBREPCB_CORE_PICKPLACECSVWRITER_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "pickplacedata.h"

#include <QtCore>

#include <memory>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {

class CsvFile;

/*******************************************************************************
 *  Class PickPlaceCsvWriter
 ******************************************************************************/

/**
 * @brief The PickPlaceCsvWriter class
 */
class PickPlaceCsvWriter final {
  Q_DECLARE_TR_FUNCTIONS(PickPlaceCsvWriter)

public:
  enum class BoardSide { Top, Bottom, Both };

  // Constructors / Destructor
  PickPlaceCsvWriter() = delete;
  PickPlaceCsvWriter(const PickPlaceCsvWriter& other) = delete;
  explicit PickPlaceCsvWriter(const PickPlaceData& data) noexcept;
  ~PickPlaceCsvWriter() noexcept;

  // Setters
  void setBoardSide(BoardSide side) noexcept { mBoardSide = side; }
  void setTypeFilter(const QSet<PickPlaceDataItem::Type>& filter) noexcept {
    mTypeFilter = filter;
  }
  void setIncludeMetadataComment(bool include) noexcept {
    mIncludeMetadataComment = include;
  }
  void setIncludeNonMountedParts(bool include) noexcept {
    mIncludeNonMountedParts = include;
  }

  // General Methods
  std::shared_ptr<CsvFile> generateCsv() const;

  // Operator Overloadings
  PickPlaceCsvWriter& operator=(const PickPlaceCsvWriter& rhs) = delete;

private:  // Methods
  static bool isOnBoardSide(const PickPlaceDataItem& item,
                            BoardSide side) noexcept;
  static QString boardSideToString(BoardSide side) noexcept;

private:  // Data
  const PickPlaceData& mData;
  BoardSide mBoardSide;
  QSet<PickPlaceDataItem::Type> mTypeFilter;
  bool mIncludeMetadataComment;
  bool mIncludeNonMountedParts;
};

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace librepcb

#endif
