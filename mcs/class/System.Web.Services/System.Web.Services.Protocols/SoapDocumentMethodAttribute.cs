// 
// System.Web.Services.Protocols.SoapDocumentMethodAttribute.cs
//
// Author:
//   Tim Coleman (tim@timcoleman.com)
//
// Copyright (C) Tim Coleman, 2002
//

using System.Web.Services.Description;

namespace System.Web.Services.Protocols {
	[AttributeUsage (AttributeTargets.Method)]
	public sealed class SoapDocumentMethodAttribute : Attribute {

		#region Fields

		string action;
		string binding;
		bool oneWay;
		SoapParameterStyle parameterStyle;
		string requestElementName;
		string requestNamespace;
		string responseElementName;
		string responseNamespace;
		SoapBindingUse use;

		#endregion

		#region Constructors

		public SoapDocumentMethodAttribute () 
		{
			action = "http://tempuri.org/MethodName"; // FIXME
			binding = String.Empty; // FIXME
			oneWay = false;
			parameterStyle = SoapParameterStyle.Wrapped;
			requestElementName = String.Empty; // FIXME
			requestNamespace = "http://tempuri.org/"; 
			responseElementName = "WebServiceNameResult"; // FIXME
			responseNamespace = "http://tempuri.org/";
			use = SoapBindingUse.Literal;
		}

		public SoapDocumentMethodAttribute (string action)
			: this ()
		{
			this.action = action;
		}
		
		#endregion // Constructors

		#region Properties

		public string Action {
			get { return action; }
			set { action = value; }
		}

		public string Binding {
			get { return binding; }
			set { binding = value; }
		}

		public bool OneWay {
			get { return oneWay; }
			set { oneWay = value; }
		}

		public SoapParameterStyle ParameterStyle {
			get { return parameterStyle; }
			set { parameterStyle = value; }
		}

		public string RequestElementName {
			get { return requestElementName; }
			set { requestElementName = value; }
		}

		public string RequestNamespace {
			get { return requestNamespace; }
			set { requestNamespace = value; }
		}

		public string ResponseElementName {
			get { return responseElementName; }
			set { responseElementName = value; }
		}

		public string ResponseNamespace {
			get { return responseNamespace; }
			set { responseNamespace = value; }
		}

		public SoapBindingUse Use {
			get { return use; }
			set { use = value; }
		}

		#endregion // Properties
	}
}
