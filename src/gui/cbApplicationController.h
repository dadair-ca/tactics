/*=========================================================================
  Program: Cerebra
  Module:  cbApplicationController.h

  Copyright (c) 2011-2013 Qian Lu, David Adair
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

  * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

  * Neither the name of the Calgary Image Processing and Analysis Centre
    (CIPAC), the University of Calgary, nor the names of any authors nor
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
=========================================================================*/

#ifndef CBAPPLICATIONCONTROLLER_H
#define CBAPPLICATIONCONTROLLER_H

#include <QObject>

class QString;
class vtkDataManager;

//! Base class for all Application controllers.
/*!
 *  Handles all progress and messaging signals.
*/
class cbApplicationController : public QObject
{
  Q_OBJECT
public:
  cbApplicationController(vtkDataManager *dataManager);
  ~cbApplicationController();

signals:
  //! Tell the cbMainWindow to display a success message.
  void displaySuccessMessage(QString message);

  //! Tell the cbMainWindow to display a notice message.
  void displayNoticeMessage(QString message);

  //! Tell the cbMainWindow to display a error message.
  void displayErrorMessage(QString message);

  //! Tell the cbMainWindow to update the progress bar.
  void displayProgress(int);

  //! Tell the cbMainWindow to initialize the progress bar.
  void initializeProgress(int, int);

protected:
  //! Pointer to the application's shared datamanager.
  vtkDataManager *dataManager;
};

#endif /* end of include guard: CBAPPLICATIONCONTROLLER_H */
