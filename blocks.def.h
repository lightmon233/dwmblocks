//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"  ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
  {" ",    "sh -c \"c=$(cat /sys/class/power_supply/BAT0/capacity); s=$(cat /sys/class/power_supply/BAT0/status); [ '$s' = 'Charging' ] && echo +$c% || echo $c%\"",    30,                 0},
	{" ", "sh -c \"pamixer --get-mute | grep -q true && echo MUTE || echo \\\"$(pamixer --get-volume)%\\\"\"",	0,		10},
	{" ", "date '+%b %d(%a) %R '",					5,		0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
