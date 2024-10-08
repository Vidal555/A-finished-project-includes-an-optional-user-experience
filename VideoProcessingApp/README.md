# Video Processing Application

## תיאור
אפליקציית עיבוד וידאו המבוססת על OpenCV. האפליקציה מאפשרת חיתוך, שינוי גודל, סיבוב, הוספת טקסט ופילטרים על קובצי וידאו.

## דרישות
- OpenCV
- GStreamer
- CMake

## התקנה
1. **התקנת OpenCV**:
   - יש להוריד ולהתקין את OpenCV למערכת שלך.
   - יש להגדיר את הנתיב ל-OpenCV במערכת.

2. **התקנת GStreamer**:
   - יש להוריד ולהתקין את GStreamer.

3. **התקנת CMake**:
   - יש להוריד ולהתקין את CMake.

## איך להריץ
1. **בניית הפרויקט**:
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build . --config Release

   ./Release/VideoProcessingApp.exe "<נתיב לקובץ הווידאו>"
"# VideoProcessingApp" 




פעולות אפשריות לאחר הרצת האפליקציה:
לאחר הפעלת האפליקציה, יופיע תפריט אינטראקטיבי שמאפשר למשתמש לבחור פעולה על הווידאו הנכנס. להלן רשימת כל הפעולות האפשריות:

Convert to another format (המרה לפורמט אחר):

פעולה זו מאפשרת להמיר את קובץ הווידאו לפורמט אחר (למשל מ-MP4 ל-AVI).
לאחר בחירת אפשרות זו, המשתמש יתבקש להזין שם לקובץ הפלט.
Trim the video (חיתוך הווידאו):

פעולה זו מאפשרת לחתוך את הווידאו מזמן התחלה לזמן סיום.
לאחר בחירת אפשרות זו, המשתמש יתבקש להזין את זמן ההתחלה (בשניות) וזמן הסיום (בשניות) של החיתוך.
Resize the video (שינוי גודל הווידאו):

פעולה זו מאפשרת לשנות את גודל הווידאו (רוחב וגובה חדשים).
המשתמש יתבקש להזין את הרוחב והגובה החדשים של הווידאו.
Rotate the video (סיבוב הווידאו):

פעולה זו מאפשרת לסובב את הווידאו בזוויות של 90, 180 או 270 מעלות.
המשתמש יתבקש להזין את זווית הסיבוב.
Add text overlay (הוספת טקסט על הווידאו):

פעולה זו מאפשרת להוסיף טקסט סטטי על גבי הווידאו.
המשתמש יתבקש להזין את הטקסט להוספה ואת המיקום שלו (מיקום X ו-Y על המסך).
Apply filter (הוספת פילטר):

פעולה זו תוסיף פילטר של גווני אפור (Grayscale) על הווידאו.
לא נדרשת הזנה נוספת של פרמטרים.
Exit (יציאה):

אפשרות זו תסיים את האפליקציה.
