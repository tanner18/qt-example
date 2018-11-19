#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>

int main(int argc, char **argv) {
    QApplication app{argc, argv};

    // Komponenten zusammenfügen
    // -Fenster
    QWidget window{};
    window.setWindowTitle("Howdy Qt");

    // -Knopf
    auto button = std::make_unique<QPushButton>("Ende");
    QObject::connect( button.get(), &QPushButton::clicked, &app, &QApplication::quit );

    // - Layout
    auto layout = std::make_unique<QVBoxLayout>();
    layout->addWidget(button.release());
    window.setLayout(layout.release());

    // start
    window.show();
    return app.exec();

}
