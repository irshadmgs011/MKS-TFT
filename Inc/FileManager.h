/*
 * FileManager.h
 *
 * Created: 06/11/2015 10:52:38
 *  Author: David
 */

#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_

#include "Vector.h"
#include "RequestTimer.h"
#include "Events.h"

namespace FileManager
{
	const size_t maxPathLength = 100;
	typedef String<maxPathLength> Path;

	class FileSet
	{
	private:
		Path requestedPath;
		Path currentPath;
		RequestTimer timer;
		int which;
		const Event fileEvent;
		int scrollOffset;
		bool IsInSubdir() const;
		const bool isFilesList;			// true for a file list, false for a macro list
		uint8_t cardNumber;

		void GetLocalFileList(const Path path);

	public:
		FileSet(Event fe, const char * array rootDir, bool pIsFilesList);
		void Display();
		void Reload(int whichList, const Path& dir, int errCode);
		void FileListUpdated();
		void Scroll(int amount);
		void SetIndex(int index) { which = index; }
		int GetIndex() const { return which; }
		void SetPath(const char * array pPath);
		const char * array GetPath() { return currentPath.c_str(); }
		void RequestParentDir()
			pre(IsInSubdir());
		void RequestSubdir(const char * array dir);
		void SetPending();
		void StopTimer() { timer.Stop(); }
		bool ProcessTimer() { return timer.Process(); }
		bool NextCard();
		bool SelectCard(unsigned int cardNum);
		void FirmwareFeaturesChanged();

	private:
		void SetupRootPath();
	};

	void BeginNewMessage();
	void EndReceivedMessage(bool displayingFileInfo);
	void BeginReceivingFiles();
	void ReceiveFile(const char * array data);
	void ReceiveDirectoryName(const char * array data);
	void ReceiveErrorCode(int err);

	void DisplayFilesList();
	void DisplayMacrosList();
	void Scroll(int amount);

	void RequestFilesSubdir(const char * array dir);
	void RequestMacrosSubdir(const char * array dir);
	void RequestFilesParentDir();
	void RequestMacrosParentDir();
	const char * array GetFilesDir();
	const char * array GetMacrosDir();

	void RefreshFilesList();
	bool ProcessTimers();
	bool NextCard();
	bool SelectCard(unsigned int cardNum);
	void SetNumVolumes(size_t n);
	void FirmwareFeaturesChanged();
	void GetLocalFileInfo(const char * array dir, const char * array file);
	const uint8_t GetFirstOnScrVol();
}

#endif /* FILEMANAGER_H_ */
