class Screen {
  public:
  void initScreen();
  void closeScreen();
  int mainMenu();

  private:
  void showBanner();
  void showOptions();
  void handlePos(int y);
};