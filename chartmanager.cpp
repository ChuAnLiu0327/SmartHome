#include "ChartManager.h"
#include <QVBoxLayout>
#include <QToolTip> // 新增：用于显示悬浮提示框

ChartManager::ChartManager(QObject *parent)
    : QObject(parent), m_chartView(nullptr), m_chart(nullptr)
{
}

ChartManager::~ChartManager()
{
}

void ChartManager::renderChart(QWidget *containerWidget,
                               const QVector<qreal> &xData,
                               const QVector<qreal> &yData,
                               const QString &xTitle,
                               const QString &yTitle,
                               ChartType type)
{
    if (!containerWidget || xData.size() != yData.size() || xData.isEmpty()) {
        return;
    }

    clearOldChart(containerWidget);

    m_chart = new QChart();
    m_chart->setAnimationOptions(QChart::SeriesAnimations);

    m_chartView = new QChartView(m_chart, containerWidget);
    m_chartView->setRenderHint(QPainter::Antialiasing);

    if (type == Line) {
        QLineSeries *series = new QLineSeries();
        for (int i = 0; i < xData.size(); ++i) {
            series->append(xData[i], yData[i]);
        }
        m_chart->addSeries(series);
        m_chart->setTitle("温度统计图");

        // --- 新增：连接悬停信号 ---
        connect(series, &QLineSeries::hovered, this, &ChartManager::onLineHovered);

        QValueAxis *axisX = new QValueAxis();
        axisX->setTitleText(xTitle);
        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText(yTitle);
        m_chart->addAxis(axisX, Qt::AlignBottom);
        m_chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisX);
        series->attachAxis(axisY);

    } else if (type == Bar) {
        QBarSeries *series = new QBarSeries();
        QBarSet *set = new QBarSet(yTitle);
        for (qreal val : yData) {
            *set << val;
        }
        series->append(set);
        m_chart->addSeries(series);
        m_chart->setTitle("柱状图");

        // --- 新增：连接悬停信号 ---
        connect(series, &QBarSeries::hovered, this, &ChartManager::onBarHovered);

        QStringList categories;
        for (qreal val : xData) categories << QString::number(val);
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        axisX->setTitleText(xTitle);
        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText(yTitle);
        m_chart->addAxis(axisX, Qt::AlignBottom);
        m_chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisX);
        series->attachAxis(axisY);

    } else if (type == Pie) {
        QPieSeries *series = new QPieSeries();
        for (int i = 0; i < xData.size(); ++i) {
            QPieSlice *slice = series->append(QString::number(xData[i]), yData[i]);
            slice->setLabelVisible();
        }
        m_chart->addSeries(series);
        m_chart->setTitle("饼图");
        m_chart->legend()->setAlignment(Qt::AlignRight);

        // --- 新增：连接悬停信号 ---
        connect(series, &QPieSeries::hovered, this, &ChartManager::onPieHovered);
    }

    QVBoxLayout *layout = new QVBoxLayout(containerWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_chartView);
    containerWidget->setLayout(layout);
}

// --- 新增：折线图悬停实现 ---
void ChartManager::onLineHovered(const QPointF &point, bool state)
{
    if (state) {
        // 鼠标移入：显示坐标
        QString text = QString("时间: %1\n温度: %2").arg(point.x()).arg(point.y());
        QToolTip::showText(QCursor::pos(), text);
    } else {
        // 鼠标移出：隐藏提示
        QToolTip::hideText();
    }
}

// --- 新增：柱状图悬停实现 ---
void ChartManager::onBarHovered(bool status, int index, QBarSet *set)
{
    if (status && set) {
        // 显示当前柱子的数值
        QString text = QString("数值: %1").arg(set->at(index));
        QToolTip::showText(QCursor::pos(), text);
    } else {
        QToolTip::hideText();
    }
}

// --- 新增：饼图悬停实现 ---
void ChartManager::onPieHovered(QPieSlice *slice, bool state)
{
    if (state && slice) {
        // 显示饼块的标签和百分比
        QString text = QString("%1\n占比: %2%")
                           .arg(slice->label())
                           .arg(slice->percentage() * 100, 0, 'f', 1);
        QToolTip::showText(QCursor::pos(), text);
    } else {
        QToolTip::hideText();
    }
}

void ChartManager::clearOldChart(QWidget *container)
{
    if (container->layout()) {
        QLayoutItem *item;
        while ((item = container->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    }
}
