/*
 *  This file is part of RawTherapee.
 *
 *  Copyright (c) 2004-2010 Gabor Horvath <hgabor@rawtherapee.com>
 *
 *  RawTherapee is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  RawTherapee is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RawTherapee.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _CAT02ADAP_H_
#define _CAT02ADAP_H_

#include <gtkmm.h>
#include "adjuster.h"
#include "toolpanel.h"

class Cat02adap :
    public ToolParamBlock,
    public AdjusterListener,
    public rtengine::AutocatListener,
    public FoldableToolPanel
{

protected:
    Adjuster* cat02;
    Adjuster* gree;
    bool lastAutocat02;
    bool lastAutogree;
    IdleRegister idle_register;
    int nextCadap;
    int nextciecam;
    double nextGree;
    Gtk::Label* labena;
    Gtk::Label* labdis;

public:

    Cat02adap();

    void read(const rtengine::procparams::ProcParams* pp, const ParamsEdited* pedited = nullptr);
    void write(rtengine::procparams::ProcParams* pp, ParamsEdited* pedited = nullptr);
    void setDefaults(const rtengine::procparams::ProcParams* defParams, const ParamsEdited* pedited = nullptr);
    void setBatchMode(bool batchMode);

    void adjusterChanged(Adjuster* a, double newval);
    void adjusterAutoToggled(Adjuster* a, bool newval);

    void enabledChanged();
    void cat02catChanged(int cat, int ciecam);
    bool cat02catComputed_();
    void cat02greeChanged(double gree);
    bool cat02greeComputed_();

//    void setAdjusterBehavior (bool threshadd);
    void trimValues(rtengine::procparams::ProcParams* pp);
};

#endif