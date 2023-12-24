rmlui:LoadFontFace("shell/assets/LatoLatin-Regular.ttf")
rmlui:LoadFontFace("shell/assets/LatoLatin-Bold.ttf")
rmlui:LoadFontFace("shell/assets/NotoEmoji-Regular.ttf", true)

gGlConfig = trap_GetGlconfig()
gContext = rmlui:CreateContext("main", Vector2i.new(gGlConfig.vidWidth, gGlConfig.vidHeight))

menu = {}
require("shell.menu.main")
require("shell.menu.start")
require("shell.menu.ingame")
