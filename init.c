void SetupDatas();
void code();

__attribute__((section(".startup"))) int startup()
{
  SetupDatas();
  code();
  return 0;
}