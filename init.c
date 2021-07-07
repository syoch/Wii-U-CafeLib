__attribute__((section(".init"))) void SetupDatas();

__attribute__((section(".startup"))) void startup()
{
  SetupDatas();
}