__attribute__((section(".init"))) void SetupDatas();
__attribute__((section(".code"))) void code();

__attribute__((section(".startup"))) int startup()
{
  SetupDatas();
  code();
  return;
}