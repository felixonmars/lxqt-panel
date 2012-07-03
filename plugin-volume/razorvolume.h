/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * Razor - a lightweight, Qt based, desktop toolset
 * http://razor-qt.org
 *
 * Copyright: 2012 Razor team
 * Authors:
 *   Johannes Zellner <webmaster@nebulon.de>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef RAZORVOLUME_H
#define RAZORVOLUME_H

#include "../panel/razorpanelplugin.h"

#include <QtGui/QSlider>

class VolumeButton;
class PulseAudioEngine;
class PulseAudioDevice;
class RazorVolumeConfiguration;

class RazorVolume : public RazorPanelPlugin
{
    Q_OBJECT
public:
    RazorVolume(const RazorPanelPluginStartInfo* startInfo, QWidget* parent = 0);
    ~RazorVolume();

    virtual RazorPanelPlugin::Flags flags() const { return PreferRightAlignment | HaveConfigDialog ; }

protected slots:
    virtual void showConfigureDialog();
    virtual void settingsChanged();
    void updateConfigurationSinkList();

private:
    PulseAudioEngine *m_paEngine;
    VolumeButton *m_volumeButton;
    int m_defaultSinkIndex;
    PulseAudioDevice *m_defaultSink;
    RazorVolumeConfiguration *m_configWindow;
};

EXPORT_RAZOR_PANEL_PLUGIN_H

#endif // RAZORVOLUME_H
