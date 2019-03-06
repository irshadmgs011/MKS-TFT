/*
 * PanelDue.h
 *
 * Created: 06/12/2014 14:23:38
 *  Author: David
 */

#ifndef PANELDUE_H_
#define PANELDUE_H_

#include "UTFT.h"
#include "Display.h"
#include "RequestTimer.h"
#include "PrinterStatus.h"
#include "UserInterface.h"

// Functions called from the serial I/O module
extern void ProcessReceivedValue(const char id[], const char val[], int index);
extern void ProcessArrayLength(const char id[], int length);
extern void StartReceivedMessage();
extern void EndReceivedMessage();

// Functions called from module UserInterface
extern bool PrintInProgress();
extern PrinterStatus GetStatus();
extern void DelayTouchLong();
extern void ShortenTouchDelay();
extern void TouchBeep();
extern void ErrorBeep();
extern void CalibrateTouch();

// Functions called from module UserInterface to manipulate non-volatile settings and associated hardware
extern void FactoryReset();
extern void SaveSettings();
extern bool IsSaveAndRestartNeeded();
extern bool IsSaveNeeded();
extern void RotateDisplay();
extern void SetBaudRate(uint32_t rate);
extern void SetBrightness (int percent);
extern void SetVolume(uint32_t newVolume);
extern void SetColourScheme(uint32_t newColours);
extern void SetLanguage(uint32_t newLanguage);
extern uint32_t GetBaudRate();
extern int GetBrightness();
extern uint32_t GetVolume();
extern FirmwareFeatures GetFirmwareFeatures();
extern const char* array CondStripDrive(const char* array arg);
extern void Reconnect();

// Global data in PanelDue.cpp that is used elsewhere
extern UTFT lcd;
extern MainWindow mgr;

class ColourScheme;
extern const ColourScheme *colours;

const size_t MIN_AXES = 3;		// the minimum number of axes we support

#endif /* PANELDUE_H_ */
