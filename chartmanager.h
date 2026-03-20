#ifndef CHARTMANAGER_H
#define CHARTMANAGER_H

#include <QObject>
#include <QWidget>
#include <QtCharts>

class ChartManager : public QObject
{
    Q_OBJECT
public:
    enum ChartType {
        Line,    // 折线图
        Bar,     // 柱状图
        Pie      // 饼图
    };

    explicit ChartManager(QObject *parent = nullptr);
    ~ChartManager();

    void renderChart(QWidget *containerWidget,
                     const QVector<qreal> &xData,
                     const QVector<qreal> &yData,
                     const QString &xTitle,
                     const QString &yTitle,
                     ChartType type);

private slots:
    // --- 新增：鼠标悬停响应的槽函数 ---
    void onLineHovered(const QPointF &point, bool state);   // 处理折线图
    void onBarHovered(bool status, int index, QBarSet *set); // 处理柱状图
    void onPieHovered(QPieSlice *slice, bool state);         // 处理饼图

private:
    QChartView *m_chartView;
    QChart *m_chart;
    void clearOldChart(QWidget *container);
};

#endif // CHARTMANAGER_H
