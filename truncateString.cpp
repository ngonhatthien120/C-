string truncateString(string s)
{
    if(s == "") return "";
    int dem;
    do {

        dem = 0;
            while ((s[0] - '0') % 3 == 0) {
                s.erase(0, 1);
                if (s == "") return s;
                dem++;
            }
            while ((s[s.size() - 1] - '0') % 3 == 0) {
                s.erase(s.size() - 1, 1);
                if (s == "") return s;
                dem++;
            }
            while (((s[s.size() - 1] - '0') + (s[0]) - '0') % 3 == 0) {
                s.erase(0, 1);
                s.erase(s.size() - 1, 1);
                if (s == "") return s;
                dem++;
            }
    } while (dem != 0);
    return s;
}
