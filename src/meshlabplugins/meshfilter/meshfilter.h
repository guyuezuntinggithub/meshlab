/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *   
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
/* History
$Log$
Revision 1.37  2006/12/27 21:41:58  pirosu
Added improvements for the standard plugin window:
split of the apply button in two buttons:ok and apply
added support for parameters with absolute and percentage values

Revision 1.36  2006/12/13 17:37:27  pirosu
Added standard plugin window support

Revision 1.35  2006/11/29 00:59:18  cignoni
Cleaned plugins interface; changed useless help class into a plain string

Revision 1.34  2006/10/22 21:09:35  cignoni
Added Close Hole

Revision 1.33  2006/10/19 08:57:45  cignoni
Added working ball pivoting and normal creation

Revision 1.32  2006/10/10 21:13:08  cignoni
Added remove non manifold and quadric simplification filter.

Revision 1.31  2006/05/25 09:46:38  cignoni
missing std and and all the other gcc detected syntax errors

****************************************************************************/

#ifndef EXTRAFILTERSPLUGIN_H
#define EXTRAFILTERSPLUGIN_H

#include <QObject>
#include <QStringList>
#include <QList>

#include <meshlab/meshmodel.h>
#include <meshlab/interfaces.h>
//#include "decimatorDialog.h"
#include "transformDialog.h"
#include "../../meshlab/GenericELDialog.h"
#include "../../meshlab/GLLogStream.h"

class ExtraMeshFilterPlugin : public QObject, public MeshFilterInterface
{
	Q_OBJECT
	Q_INTERFACES(MeshFilterInterface)

		public:
	/* naming convention :
		 - FP -> Filter Plugin
		 - name of the plugin separated by _
	*/
	enum {  FP_LOOP_SS, 
          FP_BUTTERFLY_SS, 
          FP_REMOVE_UNREFERENCED_VERTEX,
				  FP_REMOVE_DUPLICATED_VERTEX, 
          FP_REMOVE_FACES_BY_AREA,
				  FP_REMOVE_FACES_BY_EDGE,
          FP_REMOVE_NON_MANIFOLD,
          FP_LAPLACIAN_SMOOTH, 
          FP_HC_LAPLACIAN_SMOOTH, 
          FP_TWO_STEP_SMOOTH, 
          FP_CLUSTERING, 
          FP_QUADRIC_SIMPLIFICATION, 
          FP_NORMAL_EXTRAPOLATION,
          FP_MIDPOINT, 
          FP_REORIENT ,
          FP_INVERT_FACES,
				  FP_TRANSFORM,
          FP_CLOSE_HOLES_TRIVIAL,
          FP_CLOSE_HOLES_LIEPA
          } ;

	 
  
	ExtraMeshFilterPlugin();
	~ExtraMeshFilterPlugin();
	virtual const QString ST(FilterType filter);
  virtual const QString Info(QAction *);
	virtual const PluginInfo &Info();
  virtual const FilterClass getClass(QAction *);
  virtual bool getParameters(QAction *, QWidget *, MeshModel &m, FilterParameter &par);
  virtual const int getRequirements(QAction *);


	virtual bool applyFilter(QAction *filter, MeshModel &m, FilterParameter & /*parent*/, vcg::CallBackPos * cb) ;
	bool getStdFields(QAction *, MeshModel &m, StdParList &parlst,char **filterdesc);
	bool getParameters(QAction *action, QWidget *parent, MeshModel &m,FilterParameter &par,FilterParameter *srcpar);

protected:


//	RefineDialog *refineDialog;
//	DecimatorDialog *decimatorDialog;
	TransformDialog *transformDialog;
	GenericELDialog *genericELD;
};

#endif
