#ifndef AP2DATAPLOT2D_H
#define AP2DATAPLOT2D_H

#include <QWidget>
#include "ui_AP2DataPlot2D.h"
#include "AP2DataPlotThread.h"
#include "dataselectionscreen.h"
#include "qcustomplot.h"
class AP2DataPlot2D : public QWidget
{
    Q_OBJECT
    
public:
    explicit AP2DataPlot2D(QWidget *parent = 0);
    ~AP2DataPlot2D();
private slots:
    void loadButtonClicked();
    void threadDone();
    void payloadDecoded(int index,QString name,QVariantMap map);
    void itemDisabled(QString name);
    void itemEnabled(QString name);
private:
    QMap<QString,QCPAxis*> m_axisList;
    QMap<QString,QCPGraph*> m_graphList;
    int graphCount;
    QCustomPlot *m_plot;
    QCPAxisRect *m_wideAxisRect;
    QMap<QString,QList<QPair<int,QVariantMap> > > m_dataList;
    Ui::AP2DataPlot2D ui;
    AP2DataPlotThread *m_logLoaderThread;
    DataSelectionScreen *m_dataSelectionScreen;
};

#endif // AP2DATAPLOT2D_H