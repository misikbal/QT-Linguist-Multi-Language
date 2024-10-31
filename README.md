# Multi-Language Qt Application Documentation

This project is a Qt Quick-based application that supports multiple languages (English, Turkish, and Arabic) with translations managed through **Qt Linguist**. The app uses custom C++ classes (`MyLang` and `MyTranslator`) to dynamically switch languages at runtime. The UI allows users to select a language by clicking on a country flag.

## Project Structure

### Main Components

- **`main.cpp`**: Entry point of the application, initializes the translation system and launches the main QML file.
- **`mylang.h`**: Defines language options using the `QLocale` enum for supported languages.
- **`mytranslator.h`**: Manages language switching by loading appropriate translation files.
- **`main.qml`**: The main UI file that provides the layout, displays days of the week, and allows users to switch languages using flag icons.

### Translation Files

Translation files are managed using **Qt Linguist** tools and are located in the `translator` directory:
- **`translator/lang_tr.ts`**: Turkish translations.
- **`translator/lang_ar.ts`**: Arabic translations.

The `.ts` files are then compiled into `.qm` files, which are loaded dynamically based on user interaction.

## Key Components Explained

### 1. Language Enum (`mylang.h`)

Defines supported languages as enumerated values within the `MyLang` class:
```cpp
enum E_Languages {
    ENG = QLocale::English,
    TR = QLocale::Turkish,
    AR = QLocale::Arabic
};

```

## Translator Class (mytranslator.h)
```cpp
void updateLanguage(int lang) {
    switch(lang) {
        case MyLang::TR:
            mTranslator.load("lang_tr", ":/translator");
            mApp->installTranslator(&mTranslator);
            break;
        case MyLang::AR:
            mTranslator.load("lang_ar", ":/translator");
            mApp->installTranslator(&mTranslator);
            break;
        default:
            mApp->removeTranslator(&mTranslator);
            break;
    }
    emit languageChanged();
}

```


## QML UI (main.qml)
Displays days of the week, translated based on the selected language. Each flag icon calls the updateLanguage function on click to switch languages dynamically.

Translation Process with Qt Linguist
Follow these steps to add or update translations:

### Step 1: Create or Update Translation Files
Open a terminal in the project directory.
Run the following command to generate translation files (if they do not exist) or update them:

```bash
lupdate . -ts translator/lang_tr.ts translator/lang_ar.ts
```

### Step 2: Edit Translations

Open Qt Linguist (a GUI tool) to edit translations:

```bash
linguist translator/lang_tr.ts
linguist translator/lang_ar.ts
```


Use Qt Linguist to translate strings for each `.ts` file. Save your translations when complete.


### Step 3: Compile Translation
After translations are complete, compile the .ts files to .qm files using the lrelease command:
```bash
lrelease translator/lang_tr.ts translator/lang_ar.ts
```
This will produce lang_tr.qm and lang_ar.qm files in the translator directory, which are ready for runtime use.


### Step 4: Loading Translations in the Application
The MyTranslator class loads these .qm files at runtime based on user selection. The .qm files are bundled with the application and accessed via ":/translator".

## Additional Notes
Adding New Languages: To add a new language, create a new .ts file and follow the translation steps outlined above.
Updating Strings: Any new qsTr strings in QML or C++ need to be extracted with lupdate and re-translated in Qt Linguist.
