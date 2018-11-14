var list_across0 = [
'_contents.htm',
'_reference.htm',
'_index.htm',
'_search.htm',
'_external.htm'
];
var list_up0 = [
'cppad.htm',
'appendix.htm',
'deprecated.htm',
'tracknewdel.htm'
];
var list_down3 = [
'install.htm',
'theory.htm',
'ad.htm',
'adfun.htm',
'preprocessor.htm',
'multi_thread.htm',
'utility.htm',
'ipopt_solve.htm',
'example.htm',
'speed.htm',
'appendix.htm'
];
var list_down2 = [
'faq.htm',
'directory.htm',
'glossary.htm',
'bib.htm',
'wish_list.htm',
'whats_new.htm',
'deprecated.htm',
'compare_c.htm',
'numeric_ad.htm',
'addon.htm',
'license.htm'
];
var list_down1 = [
'include_deprecated.htm',
'fundeprecated.htm',
'comparechange.htm',
'omp_max_thread.htm',
'tracknewdel.htm',
'omp_alloc.htm',
'memory_leak.htm',
'epsilon.htm',
'test_vector.htm',
'cppad_ipopt_nlp.htm',
'old_atomic.htm',
'zdouble.htm',
'autotools.htm'
];
var list_down0 = [
'tracknewdel.cpp.htm'
];
var list_current0 = [
'tracknewdel.htm#Deprecated 2007-07-23',
'tracknewdel.htm#Syntax',
'tracknewdel.htm#Purpose',
'tracknewdel.htm#Include',
'tracknewdel.htm#file',
'tracknewdel.htm#line',
'tracknewdel.htm#oldptr',
'tracknewdel.htm#newlen',
'tracknewdel.htm#head newptr',
'tracknewdel.htm#ncopy',
'tracknewdel.htm#TrackNewVec',
'tracknewdel.htm#TrackNewVec.Macro',
'tracknewdel.htm#TrackNewVec.Previously Deprecated',
'tracknewdel.htm#TrackDelVec',
'tracknewdel.htm#TrackDelVec.Macro',
'tracknewdel.htm#TrackDelVec.Previously Deprecated',
'tracknewdel.htm#TrackExtend',
'tracknewdel.htm#TrackExtend.Macro',
'tracknewdel.htm#TrackExtend.Previously Deprecated',
'tracknewdel.htm#TrackCount',
'tracknewdel.htm#TrackCount.Macro',
'tracknewdel.htm#TrackCount.Previously Deprecated',
'tracknewdel.htm#Multi-Threading',
'tracknewdel.htm#Example'
];
function choose_across0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_across0[index-1];
}
function choose_up0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_up0[index-1];
}
function choose_down3(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down3[index-1];
}
function choose_down2(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down2[index-1];
}
function choose_down1(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down1[index-1];
}
function choose_down0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down0[index-1];
}
function choose_current0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_current0[index-1];
}