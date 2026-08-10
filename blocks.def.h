//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{" ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
  {" ",    "sh -c \"capacity=$(cat /sys/class/power_supply/BAT0/capacity); status=$(cat /sys/class/power_supply/BAT0/status); [ \\\"$status\\\" = \\\"Charging\\\" ] && echo \\\"+$capacity%\\\" || echo \\\"$capacity%\\\"\"",    30,                 0},
	{" ", "sh -c \"pamixer --get-mute | grep -q true && echo MUTE || echo \\\"$(pamixer --get-volume)%\\\"\"",	0,		10},
	{" ", "date '+%b %d(%a) %I:%M'",					5,		0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
