var mediaWikiLoadStart=(new Date()).getTime();function isCompatible(ua){if(ua===undefined){ua=navigator.userAgent;}return!((ua.indexOf('MSIE')!==-1&&parseFloat(ua.split('MSIE')[1])<6)||(ua.indexOf('Firefox/')!==-1&&parseFloat(ua.split('Firefox/')[1])<3)||ua.match(/BlackBerry[^\/]*\/[1-5]\./)||ua.match(/webOS\/1\.[0-4]/)||ua.match(/PlayStation/i)||ua.match(/SymbianOS|Series60/)||ua.match(/NetFront/)||ua.match(/Opera Mini/)||ua.match(/S40OviBrowser/)||(ua.match(/Glass/)&&ua.match(/Android/)));}var startUp=function(){mw.config=new mw.Map(true);mw.loader.addSource({"local":{"loadScript":"/load.php5","apiScript":"/api.php5"}});mw.loader.register([["site","1544030351",[],"site"],["noscript","1544030351",[],"noscript"],["startup","1544030351",[],"startup"],["filepage","1544030351"],["user.groups","1544030351",[],"user"],["user","1544030351",[],"user"],["user.cssprefs","1542891143",["mediawiki.user"],"private"],["user.options","1542891143",[],"private"],["user.tokens","1542891143",[],"private"
],["mediawiki.language.data","1544030351",["mediawiki.language.init"]],["mediawiki.skinning.elements","1544030351"],["mediawiki.skinning.content","1544030351"],["mediawiki.skinning.interface","1544030351"],["skins.cologneblue","1544030351"],["skins.modern","1544030351"],["skins.vector.styles","1544030351"],["skins.monobook.styles","1544030351"],["skins.vector.js","1544030351",["jquery.throttle-debounce"]],["skins.vector.collapsibleNav","1544030351",["jquery.client","jquery.cookie","jquery.tabIndex"]],["jquery","1544030351"],["jquery.appear","1544030351"],["jquery.arrowSteps","1544030351"],["jquery.async","1544030351"],["jquery.autoEllipsis","1544030351",["jquery.highlightText"]],["jquery.badge","1544030351",["mediawiki.language"]],["jquery.byteLength","1544030351"],["jquery.byteLimit","1544030351",["jquery.byteLength"]],["jquery.checkboxShiftClick","1544030351"],["jquery.chosen","1544030351"],["jquery.client","1544030351"],["jquery.color","1544030351",["jquery.colorUtil"]],[
"jquery.colorUtil","1544030351"],["jquery.cookie","1544030351"],["jquery.delayedBind","1544030351"],["jquery.expandableField","1544030351"],["jquery.farbtastic","1544030351",["jquery.colorUtil"]],["jquery.footHovzer","1544030351"],["jquery.form","1544030351"],["jquery.fullscreen","1544030351"],["jquery.getAttrs","1544030351"],["jquery.hidpi","1544030351"],["jquery.highlightText","1544030351",["jquery.mwExtension"]],["jquery.hoverIntent","1544030351"],["jquery.json","1544030351"],["jquery.localize","1544030351"],["jquery.makeCollapsible","1544030351"],["jquery.mockjax","1544030351"],["jquery.mw-jump","1544030351"],["jquery.mwExtension","1544030351"],["jquery.placeholder","1544030351"],["jquery.qunit","1544030351"],["jquery.qunit.completenessTest","1544030351",["jquery.qunit"]],["jquery.spinner","1544030351"],["jquery.jStorage","1544030351",["jquery.json"]],["jquery.suggestions","1544030351",["jquery.highlightText"]],["jquery.tabIndex","1544030351"],["jquery.tablesorter","1544030351",[
"jquery.mwExtension","mediawiki.language.months"]],["jquery.textSelection","1544030351",["jquery.client"]],["jquery.throttle-debounce","1544030351"],["jquery.validate","1544030351"],["jquery.xmldom","1544030351"],["jquery.tipsy","1544030351"],["jquery.ui.core","1544030351",[],"jquery.ui"],["jquery.ui.widget","1544030351",[],"jquery.ui"],["jquery.ui.mouse","1544030351",["jquery.ui.widget"],"jquery.ui"],["jquery.ui.position","1544030351",[],"jquery.ui"],["jquery.ui.draggable","1544030351",["jquery.ui.core","jquery.ui.mouse","jquery.ui.widget"],"jquery.ui"],["jquery.ui.droppable","1544030351",["jquery.ui.core","jquery.ui.draggable","jquery.ui.mouse","jquery.ui.widget"],"jquery.ui"],["jquery.ui.resizable","1544030351",["jquery.ui.core","jquery.ui.mouse","jquery.ui.widget"],"jquery.ui"],["jquery.ui.selectable","1544030351",["jquery.ui.core","jquery.ui.mouse","jquery.ui.widget"],"jquery.ui"],["jquery.ui.sortable","1544030351",["jquery.ui.core","jquery.ui.mouse","jquery.ui.widget"],
"jquery.ui"],["jquery.ui.accordion","1544030351",["jquery.ui.core","jquery.ui.widget"],"jquery.ui"],["jquery.ui.autocomplete","1544030351",["jquery.ui.core","jquery.ui.position","jquery.ui.widget"],"jquery.ui"],["jquery.ui.button","1544030351",["jquery.ui.core","jquery.ui.widget"],"jquery.ui"],["jquery.ui.datepicker","1544030351",["jquery.ui.core"],"jquery.ui"],["jquery.ui.dialog","1544030351",["jquery.ui.button","jquery.ui.core","jquery.ui.draggable","jquery.ui.mouse","jquery.ui.position","jquery.ui.resizable","jquery.ui.widget"],"jquery.ui"],["jquery.ui.progressbar","1544030351",["jquery.ui.core","jquery.ui.widget"],"jquery.ui"],["jquery.ui.slider","1544030351",["jquery.ui.core","jquery.ui.mouse","jquery.ui.widget"],"jquery.ui"],["jquery.ui.tabs","1544030351",["jquery.ui.core","jquery.ui.widget"],"jquery.ui"],["jquery.effects.core","1544030351",[],"jquery.ui"],["jquery.effects.blind","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.bounce","1544030351",[
"jquery.effects.core"],"jquery.ui"],["jquery.effects.clip","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.drop","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.explode","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.fade","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.fold","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.highlight","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.pulsate","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.scale","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.shake","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.slide","1544030351",["jquery.effects.core"],"jquery.ui"],["jquery.effects.transfer","1544030351",["jquery.effects.core"],"jquery.ui"],["moment","1544030351"],["mediawiki","1544030351"],["mediawiki.api","1544030351",["mediawiki.util"]],["mediawiki.api.category","1544030351",[
"mediawiki.Title","mediawiki.api"]],["mediawiki.api.edit","1544030351",["mediawiki.Title","mediawiki.api","user.tokens"]],["mediawiki.api.login","1544030351",["mediawiki.api"]],["mediawiki.api.parse","1544030351",["mediawiki.api"]],["mediawiki.api.watch","1544030351",["mediawiki.api","user.tokens"]],["mediawiki.debug","1544030351",["jquery.footHovzer","jquery.tipsy"]],["mediawiki.debug.init","1544030351",["mediawiki.debug"]],["mediawiki.feedback","1544030351",["jquery.ui.dialog","mediawiki.Title","mediawiki.api.edit","mediawiki.jqueryMsg"]],["mediawiki.hidpi","1544030351",["jquery.hidpi"]],["mediawiki.hlist","1544030351",["jquery.client"]],["mediawiki.htmlform","1544030351"],["mediawiki.icon","1544030351"],["mediawiki.inspect","1544030351",["jquery.byteLength","jquery.json"]],["mediawiki.notification","1544030351",["mediawiki.page.startup"]],["mediawiki.notify","1544030351"],["mediawiki.searchSuggest","1544030351",["jquery.client","jquery.placeholder","jquery.suggestions",
"mediawiki.api"]],["mediawiki.Title","1544030351",["jquery.byteLength","mediawiki.util"]],["mediawiki.toc","1544030351",["jquery.cookie"]],["mediawiki.Uri","1544030351"],["mediawiki.user","1544030351",["jquery.cookie","mediawiki.api","user.options","user.tokens"]],["mediawiki.util","1544030351",["jquery.client","jquery.mwExtension","mediawiki.notify","mediawiki.toc"]],["mediawiki.action.edit","1544030351",["jquery.byteLimit","jquery.textSelection","mediawiki.action.edit.styles"]],["mediawiki.action.edit.styles","1544030351"],["mediawiki.action.edit.collapsibleFooter","1544030351",["jquery.cookie","jquery.makeCollapsible","mediawiki.icon"]],["mediawiki.action.edit.preview","1544030351",["jquery.form","jquery.spinner","mediawiki.action.history.diff"]],["mediawiki.action.history","1544030351",[],"mediawiki.action.history"],["mediawiki.action.history.diff","1544030351",[],"mediawiki.action.history"],["mediawiki.action.view.dblClickEdit","1544030351",["mediawiki.page.startup",
"mediawiki.util"]],["mediawiki.action.view.metadata","1544030351"],["mediawiki.action.view.postEdit","1544030351",["jquery.cookie","mediawiki.jqueryMsg"]],["mediawiki.action.view.redirectToFragment","1544030351",["jquery.client"]],["mediawiki.action.view.rightClickEdit","1544030351"],["mediawiki.action.edit.editWarning","1544030351",["mediawiki.jqueryMsg"]],["mediawiki.action.watch.ajax","1542891143",["mediawiki.page.watch.ajax"]],["mediawiki.language","1544030351",["mediawiki.cldr","mediawiki.language.data"]],["mediawiki.cldr","1544030351",["mediawiki.libs.pluralruleparser"]],["mediawiki.libs.pluralruleparser","1544030351"],["mediawiki.language.init","1544030351"],["mediawiki.jqueryMsg","1544030351",["mediawiki.language","mediawiki.util"]],["mediawiki.language.months","1544030351",["mediawiki.language"]],["mediawiki.libs.jpegmeta","1544030351"],["mediawiki.page.gallery","1544030351"],["mediawiki.page.ready","1544030351",["jquery.checkboxShiftClick","jquery.makeCollapsible",
"jquery.mw-jump","jquery.placeholder","mediawiki.util"]],["mediawiki.page.startup","1544030351",["mediawiki.util"]],["mediawiki.page.patrol.ajax","1544030351",["jquery.spinner","mediawiki.Title","mediawiki.api","mediawiki.notify","mediawiki.page.startup","mediawiki.util","user.tokens"]],["mediawiki.page.watch.ajax","1544030351",["jquery.mwExtension","mediawiki.api.watch","mediawiki.notify","mediawiki.page.startup","mediawiki.util"]],["mediawiki.page.image.pagination","1544030351",["jquery.spinner","mediawiki.Uri","mediawiki.util"]],["mediawiki.special","1544030351"],["mediawiki.special.block","1544030351",["mediawiki.util"]],["mediawiki.special.changeemail","1544030351",["mediawiki.util"]],["mediawiki.special.changeslist","1544030351"],["mediawiki.special.changeslist.legend","1544030351"],["mediawiki.special.changeslist.legend.js","1544030351",["jquery.cookie","jquery.makeCollapsible"]],["mediawiki.special.changeslist.enhanced","1544030351"],["mediawiki.special.movePage","1544030351",[
"jquery.byteLimit"]],["mediawiki.special.pagesWithProp","1544030351"],["mediawiki.special.preferences","1544030351",["mediawiki.language"]],["mediawiki.special.recentchanges","1544030351",["mediawiki.special"]],["mediawiki.special.search","1544030351"],["mediawiki.special.undelete","1544030351"],["mediawiki.special.upload","1544030351",["mediawiki.libs.jpegmeta","mediawiki.util"]],["mediawiki.special.userlogin.common.styles","1544030351"],["mediawiki.special.userlogin.signup.styles","1544030351"],["mediawiki.special.userlogin.login.styles","1544030351"],["mediawiki.special.userlogin.common.js","1544030351"],["mediawiki.special.userlogin.signup.js","1544030351",["jquery.throttle-debounce","mediawiki.api","mediawiki.jqueryMsg"]],["mediawiki.special.javaScriptTest","1544030351",["jquery.qunit"]],["mediawiki.special.version","1544030351"],["mediawiki.legacy.ajax","1544030351",["mediawiki.legacy.wikibits","mediawiki.util"]],["mediawiki.legacy.commonPrint","1544030351"],[
"mediawiki.legacy.config","1544030351",["mediawiki.legacy.wikibits"]],["mediawiki.legacy.protect","1544030351",["jquery.byteLimit"]],["mediawiki.legacy.shared","1544030351"],["mediawiki.legacy.oldshared","1544030351"],["mediawiki.legacy.upload","1544030351",["jquery.spinner","mediawiki.Title","mediawiki.api","mediawiki.util"]],["mediawiki.legacy.wikibits","1544030351",["mediawiki.util"]],["mediawiki.ui","1544030351"],["mediawiki.ui.button","1544030351"],["oojs","1544030351"],["oojs-ui","1544030351",["oojs"]],["ext.semanticforms.wikieditor","1544030351",["ext.semanticforms.main","jquery.wikiEditor"]],["ext.semanticforms.main","1544030351",["ext.semanticforms.autogrow","ext.semanticforms.fancybox","ext.semanticforms.select2","jquery.ui.autocomplete","jquery.ui.button","jquery.ui.core","jquery.ui.sortable","jquery.ui.widget","mediawiki.util"]],["ext.semanticforms.browser","1544030351"],["ext.semanticforms.fancybox","1544030351",["ext.semanticforms.browser"]],["ext.semanticforms.dynatree",
"1544030351",["jquery.ui.widget"]],["ext.semanticforms.autogrow","1544030351"],["ext.semanticforms.popupformedit","1544030351",["ext.semanticforms.browser"]],["ext.semanticforms.autoedit","1544030351"],["ext.semanticforms.submit","1544030351"],["ext.semanticforms.collapsible","1544030351"],["ext.semanticforms.imagepreview","1544030351"],["ext.semanticforms.checkboxes","1544030351"],["ext.semanticforms.select2","1544030351",["ext.semanticforms","mediawiki.jqueryMsg"]],["ext.semanticforms.maps","1544030351"],["ext.semanticforms","1544030351"],["ext.semanticformsinputs.datepicker","1544030351",["ext.semanticforms.main","jquery.ui.datepicker"]],["ext.semanticformsinputs.timepicker","1544030351",["ext.semanticforms.main"]],["ext.semanticformsinputs.datetimepicker","1544030351",["ext.semanticformsinputs.datepicker","ext.semanticformsinputs.timepicker"]],["ext.semanticformsinputs.menuselect","1544030351",["ext.semanticforms.main"]],["ext.semanticformsinputs.regexp","1544030351",[
"ext.semanticforms.main"]],["ext.semanticformsinputs.twolistboxes","1544030351",["ext.semanticforms.main"]],["ext.semanticformsinputs.datecheck","1544030351",["ext.semanticforms.main"]],["ext.semanticdrilldown.main","1544030351",["jquery.ui.autocomplete","jquery.ui.button"]],["ext.semanticdrilldown.info","1544030351"],["sii.image","1544030351"],["jquery.wikiEditor","1544030351",["jquery.client","jquery.textSelection"],"ext.wikiEditor"],["jquery.wikiEditor.dialogs","1544030351",["jquery.tabIndex","jquery.ui.button","jquery.ui.dialog","jquery.ui.draggable","jquery.ui.resizable","jquery.wikiEditor","jquery.wikiEditor.toolbar"],"ext.wikiEditor"],["jquery.wikiEditor.dialogs.config","1544030351",["jquery.suggestions","jquery.wikiEditor","jquery.wikiEditor.dialogs","jquery.wikiEditor.toolbar.i18n","mediawiki.Title","mediawiki.jqueryMsg"],"ext.wikiEditor"],["jquery.wikiEditor.preview","1544030351",["jquery.wikiEditor"],"ext.wikiEditor"],["jquery.wikiEditor.previewDialog","1544030351",[
"jquery.wikiEditor","jquery.wikiEditor.dialogs"],"ext.wikiEditor"],["jquery.wikiEditor.publish","1544030351",["jquery.wikiEditor","jquery.wikiEditor.dialogs"],"ext.wikiEditor"],["jquery.wikiEditor.toolbar","1544030351",["jquery.async","jquery.cookie","jquery.wikiEditor","jquery.wikiEditor.toolbar.i18n"],"ext.wikiEditor"],["jquery.wikiEditor.toolbar.config","1544030351",["jquery.wikiEditor","jquery.wikiEditor.toolbar","jquery.wikiEditor.toolbar.i18n"],"ext.wikiEditor"],["jquery.wikiEditor.toolbar.i18n","1542891143",[],"ext.wikiEditor"],["ext.wikiEditor","1544030351",["jquery.wikiEditor"],"ext.wikiEditor"],["ext.wikiEditor.dialogs","1544030351",["ext.wikiEditor","ext.wikiEditor.toolbar","jquery.wikiEditor.dialogs","jquery.wikiEditor.dialogs.config"],"ext.wikiEditor"],["ext.wikiEditor.preview","1544030351",["ext.wikiEditor","jquery.wikiEditor.preview"],"ext.wikiEditor"],["ext.wikiEditor.previewDialog","1544030351",["ext.wikiEditor","jquery.wikiEditor.previewDialog"],"ext.wikiEditor"],[
"ext.wikiEditor.publish","1544030351",["ext.wikiEditor","jquery.wikiEditor.publish"],"ext.wikiEditor"],["ext.wikiEditor.tests.toolbar","1544030351",["ext.wikiEditor.toolbar"],"ext.wikiEditor"],["ext.wikiEditor.toolbar","1544030351",["ext.wikiEditor","jquery.wikiEditor.toolbar","jquery.wikiEditor.toolbar.config"],"ext.wikiEditor"],["ext.wikiEditor.toolbar.styles","1544030351",[],"ext.wikiEditor"],["ext.wikiEditor.toolbar.hideSig","1544030351",[],"ext.wikiEditor"],["ext.FancyBoxThumbs","1544030351"],["ext.MsUpload","1544030351",["jquery.ui.progressbar"]],["ext.smw","1544030351",["jquery.async"],"ext.smw"],["ext.smw.style","1544030351",["ext.smw.tooltip.styles"],"ext.smw"],["ext.jquery.jStorage","1544030351",["jquery.json"],"ext.smw"],["ext.jquery.md5","1544030351",[],"ext.smw"],["ext.smw.dataItem","1544030351",["ext.smw","mediawiki.Title","mediawiki.Uri"],"ext.smw"],["ext.smw.dataValue","1544030351",["ext.smw.dataItem"],"ext.smw"],["ext.smw.data","1544030351",["ext.smw.dataItem",
"ext.smw.dataValue"],"ext.smw"],["ext.smw.query","1544030351",["ext.smw","mediawiki.util"],"ext.smw"],["ext.smw.api","1544030351",["ext.jquery.jStorage","ext.jquery.md5","ext.smw.data","ext.smw.query"],"ext.smw"],["ext.jquery.qtip.styles","1544030351",[],"ext.smw"],["ext.jquery.qtip","1544030351",["ext.jquery.qtip.styles"],"ext.smw"],["ext.smw.tooltip.styles","1544030351",["ext.jquery.qtip.styles"],"ext.smw"],["ext.smw.tooltip","1544030351",["ext.jquery.qtip","ext.smw","ext.smw.tooltip.styles"],"ext.smw"],["ext.smw.tooltips","1542891143",["ext.smw.style","ext.smw.tooltip"],"ext.smw"],["ext.smw.autocomplete","1544030351",["jquery.ui.autocomplete"],"ext.smw"],["ext.smw.ask","1544030351",["ext.smw.autocomplete","ext.smw.style","ext.smw.tooltip"],"ext.smw"],["ext.smw.browse","1544030351",["ext.smw.autocomplete","ext.smw.style"],"ext.smw"],["ext.smw.property","1544030351",["ext.smw.autocomplete"],"ext.smw"]]);mw.config.set({"wgLoadScript":"/load.php5","debug":false,"skin":"gumax",
"stylepath":"/skins","wgUrlProtocols":"http\\:\\/\\/|https\\:\\/\\/|ftp\\:\\/\\/|ftps\\:\\/\\/|ssh\\:\\/\\/|sftp\\:\\/\\/|irc\\:\\/\\/|ircs\\:\\/\\/|xmpp\\:|sip\\:|sips\\:|gopher\\:\\/\\/|telnet\\:\\/\\/|nntp\\:\\/\\/|worldwind\\:\\/\\/|mailto\\:|tel\\:|sms\\:|news\\:|svn\\:\\/\\/|git\\:\\/\\/|mms\\:\\/\\/|bitcoin\\:|magnet\\:|urn\\:|geo\\:|\\/\\/","wgArticlePath":"/$1","wgScriptPath":"","wgScriptExtension":".php5","wgScript":"/index.php5","wgSearchType":null,"wgVariantArticlePath":false,"wgActionPaths":{},"wgServer":"https://nurdspace.nl","wgUserLanguage":"en","wgContentLanguage":"en","wgVersion":"1.23.2","wgEnableAPI":true,"wgEnableWriteAPI":true,"wgMainPageTitle":"Main Page","wgFormattedNamespaces":{"-2":"Media","-1":"Special","0":"","1":"Talk","2":"User","3":"User talk","4":"NURDspace","5":"NURDspace talk","6":"File","7":"File talk","8":"MediaWiki","9":"MediaWiki talk","10":"Template","11":"Template talk","12":"Help","13":"Help talk","14":"Category","15":"Category talk","102":
"Property","103":"Property talk","104":"Type","105":"Type talk","106":"Form","107":"Form talk","108":"Concept","109":"Concept talk","170":"Filter","171":"Filter talk","274":"Widget","275":"Widget talk"},"wgNamespaceIds":{"media":-2,"special":-1,"":0,"talk":1,"user":2,"user_talk":3,"nurdspace":4,"nurdspace_talk":5,"file":6,"file_talk":7,"mediawiki":8,"mediawiki_talk":9,"template":10,"template_talk":11,"help":12,"help_talk":13,"category":14,"category_talk":15,"property":102,"property_talk":103,"type":104,"type_talk":105,"form":106,"form_talk":107,"concept":108,"concept_talk":109,"filter":170,"filter_talk":171,"widget":274,"widget_talk":275,"image":6,"image_talk":7,"project":4,"project_talk":5},"wgContentNamespaces":[0],"wgSiteName":"NURDspace","wgFileExtensions":["png","gif","jpg","jpeg","doc","xls","mpp","pdf","ppt","tiff","bmp","docx","xlsx","pptx","ps","odt","ods","odp","odg","svg","vsd","stl","scad","mp4","icm"],"wgDBname":"nurds_nurdspace","wgFileCanRotate":true,"wgAvailableSkins":{
"gumax":"GuMax"},"wgExtensionAssetsPath":"/extensions","wgCookiePrefix":"nurds_nurdspace","wgResourceLoaderMaxQueryLength":-1,"wgCaseSensitiveNamespaces":[],"wgLegalTitleChars":" %!\"$\u0026'()*,\\-./0-9:;=?@A-Z\\\\\\^_`a-z~+\\u0080-\\uFFFF","wgResourceLoaderStorageVersion":1,"wgResourceLoaderStorageEnabled":false,"wgWikiEditorMagicWords":{"redirect":"#REDIRECT","img_right":"right","img_left":"left","img_none":"none","img_center":"center","img_thumbnail":"thumbnail","img_framed":"framed","img_frameless":"frameless"},"smw-config":{"version":"2.2.2","settings":{"smwgQMaxLimit":10000,"smwgQMaxInlineLimit":500,"namespace":{"Property":102,"Property_talk":103,"Type":104,"Type_talk":105,"Concept":108,"Concept_talk":109,"":0,"Talk":1,"User":2,"User_talk":3,"Project":4,"Project_talk":5,"File":6,"File_talk":7,"MediaWiki":8,"MediaWiki_talk":9,"Template":10,"Template_talk":11,"Help":12,"Help_talk":13,"Category":14,"Category_talk":15,"Filter":170,"Filter_talk":171}},"formats":{"table":"Table",
"list":"List","ol":"Enumeration","ul":"Itemization","category":"Category","embedded":"Embed page contents","template":"Template","feed":"RSS and Atom feed","csv":"CSV export","dsv":"DSV export","json":"JSON export","rdf":"RDF export"}}});};if(isCompatible()){document.write("\u003Cscript src=\"/load.php5?debug=false\u0026amp;lang=en\u0026amp;modules=jquery%2Cmediawiki\u0026amp;only=scripts\u0026amp;skin=gumax\u0026amp;version=20181205T171911Z\"\u003E\u003C/script\u003E");};
/* cache key: nurds_nurdspace:resourceloader:filter:minify-js:7:91874ae96548027c5b806b9239bf141b */