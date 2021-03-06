#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Windows::Foundation;

namespace Mntone { namespace Rtmp { namespace Test {

	TEST_CLASS( RtmpUriUnitTest )
	{
	public:
		TEST_METHOD( RtmpUri_1DefaultCtor )
		{
			auto rtmp = ref new RtmpUri();
			rtmp->Scheme = RtmpScheme::Rtmp;
			rtmp->Host = "127.0.0.1";
			rtmp->Port = 1935;
			rtmp->App = "flvplayback";
			rtmp->Instance = "test";
			Check( rtmp );
		}

		TEST_METHOD( RtmpUri_2CtorFromString )
		{
			auto rtmp = ref new RtmpUri( "rtmp://127.0.0.1:1935/flvplayback/test" );
			Check( rtmp );
		}

		TEST_METHOD( RtmpUri_3CtorFromUri )
		{
			auto uri = ref new Uri( "rtmp://127.0.0.1:1935/flvplayback/test" );
			auto rtmp = ref new RtmpUri( uri );
			Check( rtmp );
		}

		TEST_METHOD( RtmpUri_4 )
		{
			auto rtmpUri = ref new RtmpUri( "rtmp://85.111.3.74/radyospor/mystream.sdp" );
			Assert::IsTrue( RtmpScheme::Rtmp == rtmpUri->Scheme );
			Assert::AreEqual( L"85.111.3.74", rtmpUri->Host );
			Assert::AreEqual( 1935, rtmpUri->Port );
			Assert::AreEqual( L"radyospor", rtmpUri->App );
			Assert::AreEqual( L"mystream.sdp", rtmpUri->Instance );
		}

	private:
		void Check( RtmpUri^ rtmpUri )
		{
			Assert::IsTrue( RtmpScheme::Rtmp == rtmpUri->Scheme );
			Assert::AreEqual( L"127.0.0.1", rtmpUri->Host );
			Assert::AreEqual( 1935, rtmpUri->Port );
			Assert::AreEqual( L"flvplayback", rtmpUri->App );
			Assert::AreEqual( L"test", rtmpUri->Instance );
		}
	};

} } }