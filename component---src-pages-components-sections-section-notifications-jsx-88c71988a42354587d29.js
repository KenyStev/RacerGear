(window.webpackJsonp=window.webpackJsonp||[]).push([[17],{269:function(e,n,a){"use strict";a.r(n);var t=a(10),o=a.n(t),r=a(0),i=a.n(r),c=a(126),s=a.n(c),l=a(359),p=a.n(l),d=a(384),f=a.n(d),u=a(38),g=a.n(u),x=a(1),b=a.n(x),m=a(383),h=a.n(m),E=a(304),w=a.n(E),k=a(307),v=a.n(k),y=a(317),j=a.n(y),O=(a(53),a(290)),R={root:Object.assign({},O.h,{position:"relative",padding:"20px 15px",lineHeight:"20px",marginBottom:"20px",fontSize:"14px",backgroundColor:"white",color:"#555555",borderRadius:"0px",maxWidth:"100%",minWidth:"auto",boxShadow:"0 12px 20px -10px rgba(255, 255, 255, 0.28), 0 4px 20px 0px rgba(0, 0, 0, 0.12), 0 7px 8px -5px rgba(255, 255, 255, 0.2)"}),info:Object.assign({backgroundColor:"#00d3ee",color:"#ffffff"},O.k),success:Object.assign({backgroundColor:"#5cb860",color:"#ffffff"},O.s),warning:Object.assign({backgroundColor:"#ffa21a",color:"#ffffff"},O.x),danger:Object.assign({backgroundColor:"#f55a4e",color:"#ffffff"},O.e),primary:Object.assign({backgroundColor:"#af2cc5",color:"#ffffff"},O.n),message:{padding:"0",display:"block",maxWidth:"89%"},close:{width:"14px",height:"14px"},iconButton:{width:"24px",height:"24px",float:"right",fontSize:"1.5rem",fontWeight:"500",lineHeight:"1",position:"absolute",right:"-4px",top:"0",padding:"0"},icon:{display:"block",float:"left",marginRight:"1.071rem"},container:Object.assign({},O.d,{position:"relative"})},S=function(e){function n(n){var a;(a=e.call(this,n)||this).closeAlert=a.closeAlert.bind(g()(a));var t=n.classes,o=n.message,r=n.color,c=n.close,s=n.icon,l=[];void 0!==c&&(l=[i.a.createElement(w.a,{className:t.iconButton,key:"close","aria-label":"Close",color:"inherit",onClick:a.closeAlert},i.a.createElement(j.a,{className:t.close}))]);var p=null;switch(typeof s){case"function":p=i.a.createElement(n.icon,{className:t.icon});break;case"string":p=i.a.createElement(v.a,{className:t.icon},n.icon);break;default:p=null}return a.state={alert:i.a.createElement(h.a,{message:i.a.createElement("div",null,p,o,void 0!==c?l:null),classes:{root:t.root+" "+t[r],message:t.message+" "+t.container}})},a}o()(n,e);var a=n.prototype;return a.closeAlert=function(){this.setState({alert:null})},a.render=function(){return this.state.alert},n}(i.a.Component);S.propTypes={classes:b.a.object.isRequired,message:b.a.node.isRequired,color:b.a.oneOf(["info","success","warning","danger","primary"]),close:b.a.bool,icon:b.a.oneOfType([b.a.func,b.a.string])};var C=s()(R)(S);function N(e){var n=Object.assign({},e).classes;return i.a.createElement("div",{className:n.clearfix})}N.propTypes={classes:b.a.object.isRequired};var T=s()({clearfix:{"&:after,&:before":{display:"table",content:'" "'},"&:after":{clear:"both"}}})(N),A={section:{backgroundColor:"#FFFFFF",display:"block",width:"100%",position:"relative",padding:"0"},title:Object.assign({},O.v,{marginTop:"30px",minHeight:"32px",textDecoration:"none"}),container:O.d},W=function(e){function n(){return e.apply(this,arguments)||this}return o()(n,e),n.prototype.render=function(){var e=this.props.classes;return i.a.createElement("div",{className:e.section,id:"notifications"},i.a.createElement("div",{className:e.container},i.a.createElement("div",{className:e.title},i.a.createElement("h3",null,"Notifications"))),i.a.createElement(C,{message:i.a.createElement("span",null,i.a.createElement("b",null,"INFO ALERT:")," You've got some friends nearby, stop looking at your phone and find them..."),close:!0,color:"info",icon:"info_outline"}),i.a.createElement(C,{message:i.a.createElement("span",null,i.a.createElement("b",null,"SUCCESS ALERT:")," You've got some friends nearby, stop looking at your phone and find them..."),close:!0,color:"success",icon:p.a}),i.a.createElement(C,{message:i.a.createElement("span",null,i.a.createElement("b",null,"WARNING ALERT:")," You've got some friends nearby, stop looking at your phone and find them..."),close:!0,color:"warning",icon:f.a}),i.a.createElement(C,{message:i.a.createElement("span",null,i.a.createElement("b",null,"DANGER ALERT:")," You've got some friends nearby, stop looking at your phone and find them..."),close:!0,color:"danger",icon:"info_outline"}),i.a.createElement(T,null))},n}(i.a.Component);n.default=s()(A)(W)},290:function(e,n,a){"use strict";a.d(n,"i",function(){return t}),a.d(n,"w",function(){return o}),a.d(n,"d",function(){return i}),a.d(n,"c",function(){return r}),a.d(n,"a",function(){return c}),a.d(n,"h",function(){return s}),a.d(n,"p",function(){return l}),a.d(n,"z",function(){return p}),a.d(n,"g",function(){return d}),a.d(n,"u",function(){return f}),a.d(n,"m",function(){return u}),a.d(n,"r",function(){return g}),a.d(n,"j",function(){return x}),a.d(n,"n",function(){return b}),a.d(n,"k",function(){return m}),a.d(n,"s",function(){return h}),a.d(n,"x",function(){return E}),a.d(n,"e",function(){return w}),a.d(n,"q",function(){return k}),a.d(n,"y",function(){return v}),a.d(n,"t",function(){return y}),a.d(n,"f",function(){return j}),a.d(n,"l",function(){return O}),a.d(n,"o",function(){return R}),a.d(n,"v",function(){return S}),a.d(n,"b",function(){return C});a(53);var t=260,o={transition:"all 0.33s cubic-bezier(0.685, 0.0473, 0.346, 1)"},r={paddingRight:"15px",paddingLeft:"15px",marginRight:"auto",marginLeft:"auto",width:"100%"},i=Object.assign({},r,{"@media (min-width: 576px)":{maxWidth:"540px"},"@media (min-width: 768px)":{maxWidth:"720px"},"@media (min-width: 992px)":{maxWidth:"960px"},"@media (min-width: 1200px)":{maxWidth:"1140px"}}),c={boxShadow:"0 10px 30px -12px rgba(0, 0, 0, 0.42), 0 4px 25px 0px rgba(0, 0, 0, 0.12), 0 8px 10px -5px rgba(0, 0, 0, 0.2)"},s={fontFamily:'"Roboto", "Helvetica", "Arial", sans-serif',fontWeight:"300",lineHeight:"1.5em"},l="#9c27b0",p="#ff9800",d="#f44336",f="#4caf50",u="#00acc1",g="#e91e63",x="#999999",b={boxShadow:"0 12px 20px -10px rgba(156, 39, 176, 0.28), 0 4px 20px 0px rgba(0, 0, 0, 0.12), 0 7px 8px -5px rgba(156, 39, 176, 0.2)"},m={boxShadow:"0 12px 20px -10px rgba(0, 188, 212, 0.28), 0 4px 20px 0px rgba(0, 0, 0, 0.12), 0 7px 8px -5px rgba(0, 188, 212, 0.2)"},h={boxShadow:"0 12px 20px -10px rgba(76, 175, 80, 0.28), 0 4px 20px 0px rgba(0, 0, 0, 0.12), 0 7px 8px -5px rgba(76, 175, 80, 0.2)"},E={boxShadow:"0 12px 20px -10px rgba(255, 152, 0, 0.28), 0 4px 20px 0px rgba(0, 0, 0, 0.12), 0 7px 8px -5px rgba(255, 152, 0, 0.2)"},w={boxShadow:"0 12px 20px -10px rgba(244, 67, 54, 0.28), 0 4px 20px 0px rgba(0, 0, 0, 0.12), 0 7px 8px -5px rgba(244, 67, 54, 0.2)"},k={boxShadow:"0 4px 20px 0px rgba(0, 0, 0, 0.14), 0 7px 10px -5px rgba(233, 30, 99, 0.4)"},v=Object.assign({color:"#fff",background:"linear-gradient(60deg, #ffa726, #fb8c00)"},E),y=Object.assign({color:"#fff",background:"linear-gradient(60deg, #66bb6a, #43a047)"},h),j=Object.assign({color:"#fff",background:"linear-gradient(60deg, #ef5350, #e53935)"},w),O=Object.assign({color:"#fff",background:"linear-gradient(60deg, #26c6da, #00acc1)"},m),R=Object.assign({color:"#fff",background:"linear-gradient(60deg, #ab47bc, #8e24aa)"},b),S=(Object.assign({color:"#fff",background:"linear-gradient(60deg, #ec407a, #d81b60)"},k),Object.assign({margin:"0 20px 10px",paddingTop:"10px",borderTop:"1px solid #eeeeee",height:"auto"},s),{color:"#3C4858",margin:"1.75rem 0 0.875rem",textDecoration:"none",fontWeight:"700",fontFamily:'"Roboto Slab", "Times New Roman", serif'}),C=Object.assign({},S,{marginTop:".625rem"})}}]);
//# sourceMappingURL=component---src-pages-components-sections-section-notifications-jsx-88c71988a42354587d29.js.map