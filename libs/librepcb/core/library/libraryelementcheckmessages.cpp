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

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include "libraryelementcheckmessages.h"

/*******************************************************************************
 *  Namespace
 ******************************************************************************/
namespace librepcb {

/*******************************************************************************
 *  MsgMissingCategories
 ******************************************************************************/

MsgMissingCategories::MsgMissingCategories() noexcept
  : RuleCheckMessage(
        Severity::Error, tr("No categories set"),
        tr("It's very important to assign every library element to at least "
           "one category. Otherwise it will be very hard to find the element "
           "in the workspace library, so it's highly recommended to fix "
           "this."),
        "missing_categories") {
}

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace librepcb
