/*
	Author: Marco Costalba (C) 2005-2006

	Copyright: See COPYING file that comes with this distribution

*/
#ifndef COMMITIMPL_H
#define COMMITIMPL_H

#include "ui_commit.h"
#include "common.h"

class Git;

class CommitImpl : public QWidget, public Ui_CommitBase {
Q_OBJECT
public:
	explicit CommitImpl(Git* git);
	~CommitImpl();

signals:
	void changesCommitted(bool);

public slots:
	void pushButtonOk_clicked();
	void pushButtonCancel_clicked();
	void pushButtonUpdateCache_clicked();
	void pushButtonSettings_clicked();
	void textEditMsg_cursorPositionChanged(int,int);

private slots:
	void contextMenuPopup(const QPoint&);
	void checkAll();
	void unCheckAll();

private:
	void checkUncheck(bool checkAll);
	bool checkFiles(SList selFiles);
	bool checkMsg(QString& msg);
	bool checkPatchName(QString& patchName);
	bool checkConfirm(SCRef msg, SCRef patchName, SCList selFiles);
	void computePosition(int para, int pos, int &col_pos, int &line_pos);

	Git* git;
	QString origMsg;
};

#endif